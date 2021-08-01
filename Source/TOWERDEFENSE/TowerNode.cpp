// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerNode.h"
#include "Turret.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ATowerNode::ATowerNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	staticMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void ATowerNode::BeginPlay()
{
	Super::BeginPlay();
	canBuild = true;
}

// Called every frame
void ATowerNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

