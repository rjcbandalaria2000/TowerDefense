// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Projectile.h"



// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	turretBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Body"));
	turretBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Barrel"));
	arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Gun Point"));
	sphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Range Collider"));

	turretBody->SetupAttachment(RootComponent);
	turretBarrel->SetupAttachment(RootComponent);
	arrow->SetupAttachment(turretBarrel);
	sphereCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	/*sphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnTargetBeginOverlap);
	sphereCollider->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnTargetExitOverlap);*/
}

void ATurret::OnTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void ATurret::OnTargetExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ATurret::ShootTarget()
{
	
}

void ATurret::Aim()
{
	
}

void ATurret::OnTargetOverlap(AEnemy* target)
{
	
}

void ATurret::OnTargetExit(AEnemy* target)
{
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

