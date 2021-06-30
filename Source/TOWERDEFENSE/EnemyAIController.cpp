// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Enemy.h"

AEnemyAIController::AEnemyAIController() {



}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	enemy = Cast<AEnemy>(GetPawn());

}


