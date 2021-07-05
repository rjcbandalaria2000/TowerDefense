// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyDead, class AEnemy*, Enemy);

UCLASS()
class TOWERDEFENSE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();
	FEnemyDead enemyDied;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoint")
	int32 currentWaypoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Waypoint")
	TArray<AActor*> waypoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoint")
	int32 endWaypoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	int32 damage;

	UFUNCTION(BlueprintCallable)
	void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MoveToWaypoints();
	
	UFUNCTION()
	void AddCurrentWaypoint();

	UFUNCTION(BlueprintCallable)
	int32 GetDamage();

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
