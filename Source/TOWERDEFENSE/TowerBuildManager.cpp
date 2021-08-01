// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBuildManager.h"
#include "TowerDefenseGameModeCPP.h"
#include "TurretDataAsset.h"
#include "Kismet/GameplayStatics.h"
#include "TowerNode.h"
#include "TurretGhost.h"
#include "Turret.h"

// Sets default values
ATowerBuildManager::ATowerBuildManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerBuildManager::BeginPlay()
{
	Super::BeginPlay();
	towerGameMode = Cast<ATowerDefenseGameModeCPP>(UGameplayStatics::GetGameMode(GetWorld()));
	
}

// Called every frame
void ATowerBuildManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ATowerBuildManager::SpawnGhostTurret(int32 ghostTurretIndex)
{
	UWorld* world = GetWorld();
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	spawnedGhostTurret = world->SpawnActor<ATurretGhost>(turretData[ghostTurretIndex]->ghostTurret, turretNode->GetActorTransform(), spawnParameters);
}

void ATowerBuildManager::SpawnTurret(int32 turretIndex)
{
	if (towerGameMode->GetGold() >= turretData[turretIndex]->turretCost) {

		UWorld* world = GetWorld();
		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		spawnedTurret = world->SpawnActor<ATurret>(turretData[turretIndex]->turret, turretNode->GetActorTransform(), spawnParameters);
		towerGameMode->SetGold(towerGameMode->GetGold() - turretData[turretIndex]->turretCost);

	}
	else {
		return;
	}
	
}

void ATowerBuildManager::DestroyGhostTurret()
{
	//if (spawnedGhostTurret) {
	spawnedGhostTurret->Destroy();
	//}
	
}






