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

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Base HP")
	int32 sharedBaseHP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AActor*> playerBases;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBaseHit();
	// Listen to CoreSharedHP for Game Over 
public:
	UFUNCTION(BlueprintCallable)
	int32 GetSharedBaseHP();

	UFUNCTION(BlueprintCallable)
	void TakeDamageBase(int damage);

};
