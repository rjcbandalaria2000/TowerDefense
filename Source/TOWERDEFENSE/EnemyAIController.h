// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public: 
	
	AEnemyAIController();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AEnemy* enemy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Waypoints")
	TArray<AActor*> waypoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Waypoints")
	int32 currentWaypoint;

	//UFUNCTION()
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

public:	

	UFUNCTION()
	void SetControlledEnemy(AEnemy* controlledEnemy);

	UFUNCTION()
	void AddWaypoints(TArray<AActor*> waypointsArray);

	/*UFUNCTION()
	void MoveToWaypoint();*/
};
