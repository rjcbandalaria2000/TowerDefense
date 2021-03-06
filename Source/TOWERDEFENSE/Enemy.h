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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* boxCollider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Waypoint")
	TArray<AActor*> waypoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	int32 damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	int32 deathGold;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	bool isBurning;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	bool isSlow;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	bool hasKillBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	bool isFlying;

	UFUNCTION(BlueprintCallable)
	void Die();

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UHealthComponent* healthComponent;

	UFUNCTION(BlueprintCallable)
	int32 GetDamage();

	UFUNCTION()
	void SetDeathGold(int32 deathGoldMultiplier);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnemyDeath();
};
