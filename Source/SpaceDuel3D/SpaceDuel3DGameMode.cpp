// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDuel3D.h"
#include "SpaceDuel3DGameMode.h"
#include "MyPlayerController.h"

ASpaceDuel3DGameMode::ASpaceDuel3DGameMode()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> Ship(TEXT("Ship'/Game/Ship.Ship_C'"));
	if (Ship.Class != NULL)
	{
		DefaultPawnClass = Ship.Class;
	}
}


