// Copyright Epic Games, Inc. All Rights Reserved.

#include "EtherealGameMode.h"

#include "EL_HUD.h"
#include "EtherealPlayerController.h"
#include "EtherealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEtherealGameMode::AEtherealGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AEtherealPlayerController::StaticClass();
	HUDClass=AEL_HUD::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Ethereal/core/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Ethereal/core/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}