// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Enemy.h"
#include "Waypoint.h"

AEnemyAIController::AEnemyAIController() {



}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	enemy = Cast<AEnemy>(GetPawn());
	//MoveToWaypoint();
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (enemy) {
		enemy->AddCurrentWaypoint();
		enemy->MoveToWaypoints();
	}
	/*if (enemy) {
		currentWaypoint++;
	}*/
}

void AEnemyAIController::SetControlledEnemy(AEnemy* controlledEnemy)
{
	enemy = controlledEnemy;
}

void AEnemyAIController::AddWaypoints(TArray<AActor*> waypointsArray)
{
	for (int32 i = 0; i < waypointsArray.Num(); i++) {
		waypoints.Add(waypointsArray[i]);
	}
	
}

//void AEnemyAIController::MoveToWaypoint()
//{
//	if (enemy) {
//		if (currentWaypoint <= waypoints.Num()) {
//			for (AActor* waypoint : waypoints) {
//				AWaypoint* waypointIndex = Cast<AWaypoint>(waypoint);
//				if (waypointIndex) {
//					if (waypointIndex->GetWaypointOrder() == currentWaypoint) {
//						MoveToActor(waypointIndex, 5.0f, false);
//						break;
//					}
//				}
//			}
//		}
//	}
//
//}






