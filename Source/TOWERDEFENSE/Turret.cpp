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
	//if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
	//	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Target In Range");
	//	targets.Add(enemy);
	//	mainTarget = targets[0];
	//	OnTargetOverlap(enemy);
	//}
	
}

void ATurret::OnTargetExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
	//if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
	//	/*targets.Remove(enemy);
	//	if (targets.Num() > 0) {
	//		mainTarget = targets[0];
	//	}
	//	else {
	//		mainTarget = NULL;
	//	}*/
	//	OnTargetExit(enemy);
	//		
	//}
}

void ATurret::ShootTarget()
{
	/*if (mainTarget) {

		if (projectile) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Shooting Targer");
			UWorld* world = GetWorld();
			FActorSpawnParameters bulletSpawnParameters;
			bulletSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			AProjectile* turretProjectile = world->SpawnActor<AProjectile>(projectile, arrow->GetComponentTransform(), bulletSpawnParameters);
		
			if (turretProjectile) {
				turretProjectile->SetProjectileDamage(turretDamage);
			}
			
		}
	}
	*/
	
}

void ATurret::Aim()
{
	//if (mainTarget) {
	//	FVector targetLocation = mainTarget->GetActorLocation() + turretAimOffset;
	//	FVector turretLocation = turretBarrel->GetComponentLocation();
	//	FVector aimDirection = targetLocation - turretLocation;
	//	//FVector targetOffset = FVector(50, 0, 0);
	//	FRotator turretRotation = UKismetMathLibrary::Conv_VectorToRotator(aimDirection);

	//	turretBarrel->SetWorldRotation(turretRotation);
	//	arrow->SetWorldRotation(turretRotation);
	//	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Aiming");
	//};
}

void ATurret::OnTargetOverlap(AEnemy* target)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Target In Range");
	//targets.Add(target);
	//mainTarget = targets[0];
}

void ATurret::OnTargetExit(AEnemy* target)
{
	/*targets.Remove(target);
	if (targets.Num() > 0) {
		mainTarget = targets[0];
	}
	else {
		mainTarget = NULL;
	}*/
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (mainTarget != NULL) {
	//	mainTarget = targets[0];
	//	Aim();
	//	
	//	if (fireTime <= 0) {
	//		ShootTarget();
	//		fireTime = 1.0f / fireRate;
	//	}
	//	else {
	//		fireTime -= DeltaTime;
	//	}
	//}
}

