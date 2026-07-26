// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/GameModes/TurnBasedGameModeBase.h"

#include "TurnBasedJam/Public/Logic/Debug/TurnBasedDebugLibrary.h"
#include "TurnBasedJam/Public/Logic/GameModes/GameModesSettings.h"

void ATurnBasedGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeGameMode();
}

void ATurnBasedGameModeBase::InitializeGameMode()
{
	GameModesSettings = GetDefault<UGameModesSettings>();
	
	if (!IsValid(GameModesSettings))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameModeBase] GameModeSettings invalid!");
		return;
	}
	else UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameModeBase] GameModeSettings valid!");
}
