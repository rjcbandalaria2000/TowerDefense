// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Waypoint.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	staticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), waypoints);
	MoveToWaypoints();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::MoveToWaypoints()
{
	AEnemyAIController* enemyAIController = Cast<AEnemyAIController>(GetController());

	if (enemyAIController) {
		if (currentWaypoint <= waypoints.Num()) {
			if (currentWaypoint < endWaypoint) {
				for (AActor* waypoint : waypoints) {
					AWaypoint* waypointIndex = Cast<AWaypoint>(waypoint);
					if (waypointIndex) {
						if (waypointIndex->GetWaypointOrder() == currentWaypoint) {
							enemyAIController->MoveToActor(waypointIndex, 5.0f, false);
							//currentWaypoint++;
							break;
						}
					}
				}
			}
			
		}
	}
}

void AEnemy::AddCurrentWaypoint()
{
	currentWaypoint++;
}

// Called to bind functionality to input
//void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

