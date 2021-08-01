// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "EnemyAIController.h"
#include "WaveData.h"
#include "Engine/EngineTypes.h"
#include "TowerDefenseGameModeCPP.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"


// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("EnemySpawnPoint"));
	staticMesh->SetupAttachment(RootComponent);
	arrow->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemySpawner::SpawnEnemy()
{
	NextWaveTimer.Invalidate();
	if (numOfEnemiesToSpawn > 0) {
		
		if (waveData->GetNumOfEnemyTypes() > 0) {
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Spawn Enemy");
			UWorld* world = GetWorld();
			FActorSpawnParameters spawnParameters;
			spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AEnemy* enemy = world->SpawnActor<AEnemy>(waveData->enemies[0], GetActorTransform(), spawnParameters);
			enemy->healthComponent->InitializeHealth(waveData->healthMultiplier);
			enemy->SetDeathGold(waveData->goldMultiplier);
			AEnemyAIController* enemyController = Cast<AEnemyAIController>(enemy->GetController());
			enemyController->SetControlledEnemy(enemy);
			enemyController->AddWaypoints(waypoints);
			enemyController->MoveToWaypoint();
			numOfEnemiesToSpawn--;

			//Gets function to do after the timer expires 
			FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &AEnemySpawner::SpawnEnemy);
			//Does the Timer
			GetWorldTimerManager().SetTimer(SpawnTimer, TimeDelegate, 2.0f, false);
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Stop Spawning");
		SpawnTimer.Invalidate();
		endWave.Broadcast(this);
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::StartNextWave() {
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Wave Clear");
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Next Wave");
	if (waveData) {
		FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &AEnemySpawner::SpawnEnemy);
		//Does the Timer
		GetWorldTimerManager().SetTimer(NextWaveTimer, TimeDelegate, waveData->prepDuration, false);
	}
	
}

void AEnemySpawner::SetNumOfEnemiesToSpawn(int32 numToSpawn)
{
	numOfEnemiesToSpawn = numToSpawn;
}

