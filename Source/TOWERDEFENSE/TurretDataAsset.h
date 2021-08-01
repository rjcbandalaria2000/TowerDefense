// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TurretDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TOWERDEFENSE_API UTurretDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 turretCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class ATurret> turret;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class ATurretGhost> ghostTurret;
};
