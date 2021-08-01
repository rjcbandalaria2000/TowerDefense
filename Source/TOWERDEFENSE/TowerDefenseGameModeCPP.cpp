// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenseGameModeCPP.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerBase.h"
#include "EnemySpawner.h"
#include "WaveData.h"
#include "Engine/EngineTypes.h"

void ATowerDefenseGameModeCPP::BeginPlay() {
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerBase::StaticClass(), playerBases);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawner::StaticClass(), enemySpawners);
	for (AActor* bases : playerBases) {
		APlayerBase* base = Cast<APlayerBase>(bases);

		if (base) {
			base->baseHit.AddDynamic(this, &ATowerDefenseGameModeCPP::OnBaseHit);
		}
	}

	for (AActor* spawners : enemySpawners) {
		AEnemySpawner* spawner = Cast<AEnemySpawner>(spawners);

		if (spawner) {
			if (waveData.Num() > 0) {
				spawner->waveData = waveData[currentWave];
				spawner->SetNumOfEnemiesToSpawn(waveData[currentWave]->numOfSpawns);
				spawner->SpawnEnemy();
			}
			
			spawner->endWave.AddDynamic(this, &ATowerDefenseGameModeCPP::OnWaveEnd);
		}
	}

}


void ATowerDefenseGameModeCPP::OnWaveEnd(AEnemySpawner* enemySpawner)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::FromInt(enemyKills));
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::FromInt(enemySpawner->waveData->numOfSpawns * (enemySpawners.Num())));
	if (currentWave < waveData.Num() - 1) {

		if (enemyKills >= enemySpawner->waveData->numOfSpawns * (enemySpawners.Num())) {
		
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Enemies clear");
			totalEnemyKills += enemyKills;
			enemyKills = 0;
			currentWave++;
			for (int32 i = 0; i < enemySpawners.Num(); i++) {
				AEnemySpawner* spawner = Cast<AEnemySpawner>(enemySpawners[i]);
				if (waveData.Num() > 0) {
					spawner->waveData = waveData[currentWave];
					spawner->SetNumOfEnemiesToSpawn(waveData[currentWave]->numOfSpawns);
					spawner->StartNextWave();
				}
				
			}
			waveEndTimer.Invalidate();
		}
	
	
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Enemies still not clear");
			//Gets function to do after the timer expires 
			FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &ATowerDefenseGameModeCPP::OnWaveEnd, enemySpawner);
			//Does the Timer
			GetWorldTimerManager().SetTimer(waveEndTimer, TimeDelegate, 2.0f, false);
		}
	}
	
	
}

void ATowerDefenseGameModeCPP::OnBaseHit(APlayerBase* base)
{
	TakeDamageBase(1);
	enemyKills++;
}

int32 ATowerDefenseGameModeCPP::GetSharedBaseHP() {
	return sharedBaseHP;
}

void ATowerDefenseGameModeCPP::TakeDamageBase(int damage)
{
	sharedBaseHP -= damage;
	if (sharedBaseHP <= 0) {
		sharedBaseHP = 0;
		CoreDeath();
	}
}

int32 ATowerDefenseGameModeCPP::GetEnemyKills()
{
	return enemyKills;
}

int32 ATowerDefenseGameModeCPP::GetTotalEnemyKills()
{
	return totalEnemyKills;
}

void ATowerDefenseGameModeCPP::AddEnemyKills()
{
	enemyKills++;
}




