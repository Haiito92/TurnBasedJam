// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/GameModes/TurnBasedGameMode.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/GameModes/GameModesSettings.h"
#include "Logic/TurnMechanic/TurnManager.h"

void ATurnBasedGameMode::InitializeGameMode()
{
	Super::InitializeGameMode();
	
	TurnManager = NewObject<UTurnManager>(this, GameModesSettings->TurnManagerClass.LoadSynchronous());
	
	if (!IsValid(TurnManager))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameMode] Wrong init, invalid TurnManager.");
	}
	else UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameMode] TurnManager valid!");
}
