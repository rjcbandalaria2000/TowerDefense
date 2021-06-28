// Copyright Epic Games, Inc. All Rights Reserved.

#include "TOWERDEFENSEGameMode.h"
#include "TOWERDEFENSEPlayerController.h"
#include "TOWERDEFENSECharacter.h"
#include "UObject/ConstructorHelpers.h"

ATOWERDEFENSEGameMode::ATOWERDEFENSEGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATOWERDEFENSEPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}