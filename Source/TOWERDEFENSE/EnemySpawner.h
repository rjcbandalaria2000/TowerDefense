// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaveEnd, class AEnemySpawner*, EnemySpawner);

UCLASS()
class TOWERDEFENSE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();
	FWaveEnd endWave;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 currentWave = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoints")
	TArray<AActor*> waypoints;

	UPROPERTY(VisibleAnywhere)
	//Delay Spawn Timer
	FTimerHandle SpawnTimer;

	UPROPERTY(VisibleAnywhere)
	//Spawn Timer
	FTimerHandle NextWaveTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Data")
	TArray<class UWaveData*> waveData;
	UFUNCTION()
	void StartNextWave();
	UFUNCTION()
	void SpawnEnemy();
	UFUNCTION()
	int32 GetCurrentWave();
};
