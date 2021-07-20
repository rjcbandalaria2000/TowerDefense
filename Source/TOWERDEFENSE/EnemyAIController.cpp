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
	MoveToWaypoint();
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	/*if (enemy) {
		enemy->AddCurrentWaypoint();
		enemy->MoveToWaypoints();
	}*/
	if (enemy) {
		//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "MoveToNext");
		currentWaypoint++;
		MoveToWaypoint();
	}
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

void AEnemyAIController::MoveToWaypoint()
{
	//if (enemy) {
	//	if (currentWaypoint <= waypoints.Num()) {
	//		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Current Next");
	//		for (AActor* waypoint : waypoints) {
	//			AWaypoint* waypointIndex = Cast<AWaypoint>(waypoint);
	//			if (waypointIndex) {
	//				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Next Waypoint");
	//				//if (waypointIndex->GetWaypointOrder() == currentWaypoint) {
	//					MoveToActor(waypointIndex, 5.0f, false);
	//					break;
	//				//}
	//			}
	//		}
	//	}
	//}
	if (enemy) {
		if (currentWaypoint <= waypoints.Num()) {
			AWaypoint* waypointIndex = Cast<AWaypoint>(waypoints[currentWaypoint]);
			if (waypointIndex) {
				MoveToActor(waypointIndex, 5.0f, false);
			}
			
		}
	}
}






