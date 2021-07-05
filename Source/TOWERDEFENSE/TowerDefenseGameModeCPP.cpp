// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenseGameModeCPP.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerBase.h"

void ATowerDefenseGameModeCPP::BeginPlay() {
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerBase::StaticClass(), playerBases);
	
	for (AActor* bases : playerBases) {
		APlayerBase* base = Cast<APlayerBase>(bases);

		if (base) {
			base->baseHit.AddDynamic(this, &ATowerDefenseGameModeCPP::OnBaseHit);
		}
	}

}

void ATowerDefenseGameModeCPP::OnBaseHit()
{
	TakeDamageBase(1);
}

int32 ATowerDefenseGameModeCPP::GetSharedBaseHP() {
	return sharedBaseHP;
}

void ATowerDefenseGameModeCPP::TakeDamageBase(int damage)
{
	if (sharedBaseHP > 0) {
		sharedBaseHP -= damage;
	}
}


