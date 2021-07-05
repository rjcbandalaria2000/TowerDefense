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
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Binded with OnBaseHit");
			base->baseHit.AddDynamic(this, &ATowerDefenseGameModeCPP::OnBaseHit);
		}
	}

}


void ATowerDefenseGameModeCPP::OnBaseHit(APlayerBase* base)
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


