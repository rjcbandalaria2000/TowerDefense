// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerBuildManager.generated.h"

UCLASS()
class TOWERDEFENSE_API ATowerBuildManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerBuildManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class ATowerDefenseGameModeCPP* towerGameMode;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ATowerNode* turretNode;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ATurret* spawnedTurret;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ATurretGhost* spawnedGhostTurret;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret Data")
	TArray<class UTurretDataAsset*> turretData;

	UFUNCTION(BlueprintCallable)
	void SpawnGhostTurret(int32 ghostTurretIndex);

	UFUNCTION(BlueprintCallable)
	void SpawnTurret(int32 turretIndex);

	UFUNCTION(BlueprintCallable)
	void DestroyGhostTurret();

};
