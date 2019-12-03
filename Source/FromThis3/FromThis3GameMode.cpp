// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FromThis3GameMode.h"
#include "FromThis3Character.h"
#include "UObject/ConstructorHelpers.h"

AFromThis3GameMode::AFromThis3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
