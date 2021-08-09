// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turret.h"
#include "MissileTurret.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AMissileTurret : public ATurret
{
	GENERATED_BODY()

public:


protected:
	virtual void BeginPlay() override;

	virtual void OnTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnTargetExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual void ShootTarget() override;

	virtual void Aim() override;

	virtual void OnTargetOverlap(AEnemy* target) override;

	virtual void OnTargetExit(AEnemy* target) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
