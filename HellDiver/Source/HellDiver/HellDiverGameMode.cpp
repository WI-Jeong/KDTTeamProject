// Copyright Epic Games, Inc. All Rights Reserved.

#include "HellDiverGameMode.h"
#include "HellDiverCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHellDiverGameMode::AHellDiverGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
