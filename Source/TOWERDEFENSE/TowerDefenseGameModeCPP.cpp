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
			spawner->endWave.AddDynamic(this, &ATowerDefenseGameModeCPP::OnWaveEnd);
		}
	}

}


void ATowerDefenseGameModeCPP::OnWaveEnd(AEnemySpawner* enemySpawner)
{
	//if(enemyKills >= totalNumOfEnemiesSpawned)
	totalEnemyKills += enemyKills;
	enemyKills = 0;
	enemySpawner->SpawnEnemy();
	
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Enemies still not clear");
	//	FTimerHandle waveEndTimer;
	//	//Gets function to do after the timer expires 
	//	FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &ATowerDefenseGameModeCPP::OnWaveEnd, enemySpawner);
	//	//Does the Timer
	//	GetWorldTimerManager().SetTimer(waveEndTimer, TimeDelegate, 2.0f, false);
	//}
	
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




