// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WaveData.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class TOWERDEFENSE_API UWaveData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float duration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 numOfSpawns;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<class AEnemy>> enemies;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AEnemy> bossEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Reward")
	int32 killReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Reward")
	int32 clearReward;

	UFUNCTION(BlueprintPure, BlueprintCallable)
	int32 TotalKillReward();

	UFUNCTION()
	float GetDuration();

	UFUNCTION()
	int32 GetNumOfSpawns();

	UFUNCTION()
	int32 GetKillReward();
	
	UFUNCTION()
	int32 GetClearReward();

	UFUNCTION()
	int32 GetNumOfEnemyTypes();


};
