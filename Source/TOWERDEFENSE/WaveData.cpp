// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveData.h"
#include "Enemy.h"

int32 UWaveData::TotalKillReward() {
	return killReward * numOfSpawns;
}

float UWaveData::GetDuration() {
	return duration;
}

int32 UWaveData::GetNumOfSpawns() {
	return numOfSpawns;
}

int32 UWaveData::GetKillReward()
{
	return killReward;
}

int32 UWaveData::GetClearReward()
{
	return clearReward;
}

int32 UWaveData::GetNumOfEnemyTypes() {
	return enemies.Num();
}
