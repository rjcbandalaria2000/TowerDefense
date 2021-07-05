// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBase.generated.h"

// Event Dispatcher that broadcasts when hit by enemy 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageBase, class APlayerBase*, PlayerBase);

UCLASS()
class TOWERDEFENSE_API APlayerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBase();
	FDamageBase baseHit;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UHealthComponent* healthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* boxCollider;

	UFUNCTION(BlueprintCallable)
	void OnBeginOverlapBase(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHit(AEnemy* enemy);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
