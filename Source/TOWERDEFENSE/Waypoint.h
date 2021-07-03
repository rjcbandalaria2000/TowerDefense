// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Waypoint.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AWaypoint : public AStaticMeshActor
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 waypointOrder;

public: 
	UFUNCTION()
	int32 GetWaypointOrder();
};
