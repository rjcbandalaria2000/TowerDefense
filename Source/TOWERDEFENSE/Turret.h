// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

UCLASS()
class TOWERDEFENSE_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* turretBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* turretBarrel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UArrowComponent* arrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* sphereCollider;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<class AEnemy*> targets;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AEnemy* mainTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AProjectile> projectile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float fireRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float fireTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector turretAimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 turretDamage;

	UFUNCTION()
	void OnTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnTargetExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION()
	virtual void ShootTarget();
	
	UFUNCTION()
	void Aim();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
