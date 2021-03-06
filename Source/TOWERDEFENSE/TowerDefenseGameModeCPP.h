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
	int32 enemyKills;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 totalEnemyKills;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AActor*> playerBases;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<AActor*> enemySpawners;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTimerHandle waveEndTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 currentWave = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 gold = 0;

	
	UFUNCTION()
	void OnWaveEnd(class AEnemySpawner* enemySpawner);

	UFUNCTION()
	void OnBaseHit(class APlayerBase* base);

	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Data");
	TArray<class UWaveData*> waveData;

	UFUNCTION(BlueprintCallable)
	int32 GetSharedBaseHP();

	UFUNCTION(BlueprintCallable)
	void TakeDamageBase(int damage);

	UFUNCTION(BlueprintCallable)
	int32 GetEnemyKills();

	UFUNCTION(BlueprintCallable)
	int32 GetTotalEnemyKills();

	UFUNCTION(BlueprintCallable)
	void AddEnemyKills();

	UFUNCTION(BlueprintImplementableEvent)
	void CoreDeath();

	UFUNCTION()
	int32 GetGold();

	UFUNCTION()
	void SetGold(int32 newGold);
};
