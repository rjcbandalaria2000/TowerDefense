// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Waypoint.h"
#include "TowerDefenseGameModeCPP.h"
#include "HealthComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), waypoints);
	healthComponent->unitDied.AddDynamic(this, &AEnemy::OnEnemyDeath);
	//healthComponent->InitializeHealth();
}

void AEnemy::Die()
{
	this->Destroy();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


int32 AEnemy::GetDamage()
{
	return damage;
}

void AEnemy::SetDeathGold(int32 deathGoldMultiplier)
{
	deathGold *= deathGoldMultiplier;
}




