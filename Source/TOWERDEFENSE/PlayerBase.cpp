// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "HealthComponent.h"
#include "Components/BoxComponent.h"
#include "Enemy.h"



// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));

	staticMesh->SetupAttachment(RootComponent);
	boxCollider->SetupAttachment(RootComponent);
	AddOwnedComponent(healthComponent);
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &APlayerBase::OnBeginOverlapBase);
	
}

void APlayerBase::OnBeginOverlapBase(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
		OnHit(enemy);
		baseHit.Broadcast(this);
	}
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

