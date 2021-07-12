// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "EnemyAIController.h"

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
	if (enemyTypes.Num() > 0) {
		
		SpawnEnemy();

		
	}
	
	
}

void AEnemySpawner::SpawnEnemy()
{
	if (enemyTypes.Num() > 0) {

		UWorld* world = GetWorld();
		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AEnemy* enemy = world->SpawnActor<AEnemy>(enemyTypes[0], GetActorTransform(), spawnParameters);
		enemy->SetCurrentWaypoint(intendedWaypoint);
		enemy->SetEndWaypoint(intendedEndWaypoint);
		enemy->MoveToWaypoints();
		
		AEnemyAIController* enemyController = Cast<AEnemyAIController>(enemy->GetController());
		enemyController->SetControlledEnemy(enemy);

		//Destroy Tiles
		FTimerHandle SpawnTimer;
		//Gets function to do after the timer expires 
		FTimerDelegate TimeDelegate = FTimerDelegate::CreateUObject(this, &AEnemySpawner::SpawnEnemy);
		//Does the Timer
		GetWorldTimerManager().SetTimer(SpawnTimer, TimeDelegate, 2.0f, false);

		
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

