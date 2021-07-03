// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "HealthComponent.h"



// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

	staticMesh->SetupAttachment(RootComponent);
	AddOwnedComponent(healthComponent);

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

