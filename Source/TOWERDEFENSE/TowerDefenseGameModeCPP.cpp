// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenseGameModeCPP.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerBase.h"
#include "EnemySpawner.h"

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
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Binded with OnWaveEnd");
			spawner->endWave.AddDynamic(this, &ATowerDefenseGameModeCPP::OnWaveEnd);
		}
	}

}


void ATowerDefenseGameModeCPP::OnWaveEnd(AEnemySpawner* enemySpawner)
{
	totalEnemyKills += enemyKills;
	enemyKills = 0;
	//enemySpawner->StartNextWave();
	enemySpawner->SpawnEnemy();
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
	if (sharedBaseHP > 0) {
		sharedBaseHP -= damage;
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




