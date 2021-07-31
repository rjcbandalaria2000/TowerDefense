// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerNode.generated.h"

UCLASS()
class TOWERDEFENSE_API ATowerNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UArrowComponent* turretBuildPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class ATurret* turretBuilt;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
