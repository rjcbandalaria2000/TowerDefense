// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Waypoint.h"
#include "TowerDefenseGameModeCPP.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), waypoints);
	//MoveToWaypoints();
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

//void AEnemy::MoveToWaypoints()
//{
//	AEnemyAIController* enemyAIController = Cast<AEnemyAIController>(GetController());
//
//	if (enemyAIController) {
//		if (currentWaypoint <= waypoints.Num()) {
//			if (currentWaypoint < endWaypoint) {
//				for (AActor* waypoint : waypoints) {
//					AWaypoint* waypointIndex = Cast<AWaypoint>(waypoint);
//					if (waypointIndex) {
//						if (waypointIndex->GetWaypointOrder() == currentWaypoint) {
//							enemyAIController->MoveToActor(waypointIndex, 5.0f, false);
//							break;
//						}
//					}
//				}
//			}
//			
//		}
//	}
//}

void AEnemy::AddCurrentWaypoint()
{
	currentWaypoint++;
}

int32 AEnemy::GetDamage()
{
	return damage;
}

int32 AEnemy::GetCurrentWaypoint()
{
	return currentWaypoint;
}

void AEnemy::SetCurrentWaypoint(int32 intendedWaypointIndex)
{
	currentWaypoint = intendedWaypointIndex;
}

int32 AEnemy::GetEndWaypoint()
{
	return endWaypoint;
}

void AEnemy::SetEndWaypoint(int32 endWaypointIndex)
{
	endWaypoint = endWaypointIndex;
}


