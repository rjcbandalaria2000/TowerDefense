// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TowerDefenseGameModeCPP.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATowerDefenseGameModeCPP : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
protected: 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Base HP")
	int32 sharedBaseHP;

public:
	/*UFUNCTION()
	int32 GetSharedBaseHP();*/

};
