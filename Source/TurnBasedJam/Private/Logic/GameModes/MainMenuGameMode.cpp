// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/GameModes/MainMenuGameMode.h"
#include "Logic/PlayerControllers/TurnBasedPlayerControllerBase.h"

void AMainMenuGameMode::StartGame()
{
	Super::StartGame();
	
	FInputModeUIOnly InputModeData = {};
	PlayerController->SetInputMode(InputModeData);
	PlayerController->SetShowMouseCursor(true);
}
