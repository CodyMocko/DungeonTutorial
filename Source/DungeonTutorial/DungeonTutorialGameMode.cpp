// Copyright Epic Games, Inc. All Rights Reserved.

#include "DungeonTutorialGameMode.h"
#include "DungeonTutorialCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeonTutorialGameMode::ADungeonTutorialGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
