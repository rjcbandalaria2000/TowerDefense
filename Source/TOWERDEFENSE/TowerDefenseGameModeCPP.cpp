// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenseGameModeCPP.h"

int32 ATowerDefenseGameModeCPP::GetSharedBaseHP() {
	return sharedBaseHP;
}

void ATowerDefenseGameModeCPP::TakeDamageBase(int damage)
{
	if (sharedBaseHP > 0) {
		sharedBaseHP -= damage;
	}
}


