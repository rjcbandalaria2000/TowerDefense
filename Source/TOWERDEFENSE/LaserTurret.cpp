// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserTurret.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Projectile.h"

void ALaserTurret::BeginPlay() {
	Super::BeginPlay();
	sphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ALaserTurret::OnTargetBeginOverlap);
	sphereCollider->OnComponentEndOverlap.AddDynamic(this, &ALaserTurret::OnTargetExitOverlap);
}

void ALaserTurret::OnTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTargetBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {
		OnTargetOverlap(enemy);
	}
}

void ALaserTurret::OnTargetExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnTargetExitOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor)) {

		OnTargetExit(enemy);

	}
}

void ALaserTurret::ShootTarget()
{
	Super::ShootTarget();
	if (mainTarget) {

		if (projectile) {
			UWorld* world = GetWorld();
			FActorSpawnParameters bulletSpawnParameters;
			bulletSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AProjectile* turretProjectile = world->SpawnActor<AProjectile>(projectile, arrow->GetComponentTransform(), bulletSpawnParameters);

			if (turretProjectile) {
				turretProjectile->SetProjectileDamage(turretDamage);
				//turretProjectile->SetTarget(mainTarget);
				//turretProjectile->LockOnToTarget();
			}

		}
	}
}

void ALaserTurret::Aim()
{
	Super::Aim();
	if (mainTarget) {
		FVector targetLocation = mainTarget->GetActorLocation() + turretAimOffset;
		FVector turretLocation = turretBarrel->GetComponentLocation();
		FVector aimDirection = targetLocation - turretLocation;
		//FVector targetOffset = FVector(50, 0, 0);
		FRotator turretRotation = UKismetMathLibrary::Conv_VectorToRotator(aimDirection);

		turretBarrel->SetWorldRotation(turretRotation);
		arrow->SetWorldRotation(turretRotation);
	};
}

void ALaserTurret::OnTargetOverlap(AEnemy* target)
{
	Super::OnTargetOverlap(target);
	targets.Add(target);
	mainTarget = targets[0];
}

void ALaserTurret::OnTargetExit(AEnemy* target)
{
	Super::OnTargetExit(target);
	targets.Remove(target);
	if (targets.Num() > 0) {
		mainTarget = targets[0];
	}
	else {
		mainTarget = NULL;
	}
}

void ALaserTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (mainTarget != NULL) {
		mainTarget = targets[0];
		Aim();

		if (fireTime <= 0) {
			ShootTarget();
			fireTime = 1.0f / fireRate;
		}
		else {
			fireTime -= DeltaTime;
		}
	}
}
