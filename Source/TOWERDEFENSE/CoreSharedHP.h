// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoreSharedHP.generated.h"

// Event Dispatcher for when core is dead

UCLASS()
class TOWERDEFENSE_API ACoreSharedHP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoreSharedHP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Listens to the call of the Player Base 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
