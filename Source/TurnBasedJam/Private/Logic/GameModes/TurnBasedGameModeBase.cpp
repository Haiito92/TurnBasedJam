// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/GameModes/TurnBasedGameModeBase.h"

#include "TurnBasedJam/Public/Logic/Debug/TurnBasedDebugLibrary.h"
#include "TurnBasedJam/Public/Logic/GameModes/GameModesSettings.h"

void ATurnBasedGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (!InitializeGameMode())
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameModeBase] Initialization failed.");
		return;
	}
	
	
}

bool ATurnBasedGameModeBase::InitializeGameMode()
{
	GameModesSettings = GetDefault<UGameModesSettings>();
	
	if (!IsValid(GameModesSettings))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameModeBase] GameModeSettings invalid!");
		return false;
	}
	else UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameModeBase] GameModeSettings valid!");

	return true;
}

void ATurnBasedGameModeBase::StartGame()
{
	
}
