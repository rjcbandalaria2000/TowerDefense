// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TOWERDEFENSE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UArrowComponent* arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Config")
	int32 numOfEnemiesToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner Config")
	TArray<TSubclassOf<class AEnemy>> enemyTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Enemy Spawn Config")
	int32 intendedWaypoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Spawn Config")
	int32 intendedEndWaypoint;

	UFUNCTION()
	void SpawnEnemy();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
