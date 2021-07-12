// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "EnemyAIController.h"
#include "WaveData.h"
#include "Engine/EngineTypes.h"

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
	//currentWave = 0; 
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	numOfEnemiesToSpawn = waveData[currentWave]->GetNumOfSpawns();
	if (waveData.Num()  > 0) {
		SpawnEnemy();
	}
}

void AEnemySpawner::SpawnEnemy()
{
	if (numOfEnemiesToSpawn > 0) {

		if (waveData[currentWave]->GetNumOfEnemyTypes() > 0) {

			UWorld* world = GetWorld();
			FActorSpawnParameters spawnParameters;
			spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AEnemy* enemy = world->SpawnActor<AEnemy>(enemyTypes[0], GetActorTransform(), spawnParameters);
			enemy->SetCurrentWaypoint(intendedWaypoint);
			enemy->SetEndWaypoint(intendedEndWaypoint);
			enemy->MoveToWaypoints();

			AEnemyAIController* enemyController = Cast<AEnemyAIController>(enemy->GetController());
			enemyController->SetControlledEnemy(enemy);
			numOfEnemiesToSpawn--;

			//Gets function to do after the timer expires 
			FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &AEnemySpawner::SpawnEnemy);
			//Does the Timer
			GetWorldTimerManager().SetTimer(SpawnTimer, TimeDelegate, 2.0f, false);


		}
	}
	else {
		SpawnTimer.Invalidate();
		//Gets function to do after the timer expires 
		FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &AEnemySpawner::StartNextWave);
		//Does the Timer
		GetWorldTimerManager().SetTimer(NextWaveTimer, TimeDelegate, 5.0f, false);

	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::StartNextWave() {
	NextWaveTimer.Invalidate();
	if (currentWave < waveData.Num()) {
		currentWave++;
		SpawnEnemy();
		numOfEnemiesToSpawn = waveData[currentWave]->GetNumOfSpawns();
	}
	else {
		return;
	}
	
}

