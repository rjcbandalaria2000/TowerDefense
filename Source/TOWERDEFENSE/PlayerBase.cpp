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
	boxCollider->OnComponentHit.AddDynamic(this, &APlayerBase::OnHitBase);
	
}

void APlayerBase::OnHitBase(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
		OnHit(enemy);
	}
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

