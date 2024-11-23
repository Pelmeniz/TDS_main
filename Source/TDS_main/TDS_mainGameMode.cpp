// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDS_mainGameMode.h"
#include "TDS_mainPlayerController.h"
#include "TDS_mainCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDS_mainGameMode::ATDS_mainGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDS_mainPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}