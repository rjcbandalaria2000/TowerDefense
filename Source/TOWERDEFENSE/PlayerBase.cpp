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
	//boxCollider->OnComponentHit.AddDynamic(this, &APlayerBase::OnHitBase);
	
}

//void APlayerBase::OnHitBase(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Hit");
//	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Overlap with Enemy");
//		OnHit(enemy);
//	}
//}

void APlayerBase::OnBeginOverlapBase(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Overlapped");
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Overlap with Enemy");
		OnHit(enemy);
	}
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

