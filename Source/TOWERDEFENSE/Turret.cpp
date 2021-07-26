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
	sphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnTargetBeginOverlap);
	sphereCollider->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnTargetExitOverlap);
}

void ATurret::OnTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Target In Range");
		targets.Add(enemy);
		mainTarget = targets[0];
		ShootTarget();
	}
}

void ATurret::OnTargetExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Target Out of Range");
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Target Out of Range");
		targets.Remove(enemy);
		if (targets.Num() > 0) {
			mainTarget = targets[0];
		}
		else {
			mainTarget = NULL;
		}
			
	}
}

void ATurret::ShootTarget()
{
	
}

void ATurret::Aim()
{
	if (mainTarget) {
		FVector targetLocation = mainTarget->GetActorLocation();
		FVector turretLocation = turretBarrel->GetComponentLocation();
		FVector aimDirection = targetLocation - turretLocation;

		FRotator turretRotation = UKismetMathLibrary::Conv_VectorToRotator(aimDirection);

		turretBarrel->SetWorldRotation(turretRotation);
		arrow->SetWorldRotation(turretRotation);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Aiming");
	};
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (targets.Num() > 0) {
		mainTarget = targets[0];
		Aim();
	}
}

