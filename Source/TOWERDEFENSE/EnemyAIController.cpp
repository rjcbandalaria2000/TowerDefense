// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Enemy.h"

AEnemyAIController::AEnemyAIController() {



}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	enemy = Cast<AEnemy>(GetPawn());
	if (enemy) {
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Casted to Enemy");
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Cast to Enemy Failed");
	}

}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "MoveCompleted");
	if (enemy) {
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "Next Waypoint");
		enemy->AddCurrentWaypoint();
		enemy->MoveToWaypoints();
	}
}

void AEnemyAIController::SetControlledEnemy(AEnemy* controlledEnemy)
{
	enemy = controlledEnemy;
}






