// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/GameModes/TurnBasedGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "Logic/HUDs/TurnBasedHUDBase.h"
#include "Logic/PlayerControllers/TurnBasedPlayerControllerBase.h"
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
	
	StartGame();
}

bool ATurnBasedGameModeBase::InitializeGameMode()
{
	if (!InitializeGame())
	{
		return false;
	}
	
	if (!InitializeUI())
	{
		return false;
	}
	
	return true;
}

bool ATurnBasedGameModeBase::InitializeGame()
{
	GameModesSettings = GetDefault<UGameModesSettings>();
	
	if (!IsValid(GameModesSettings))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameModeBase] Failed init, GameModeSettings invalid!");
		return false;
	}
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameModeBase] GameModeSettings valid!");

	PlayerController = Cast<ATurnBasedPlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	
	if (!IsValid(PlayerController))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameModeBase] Failed init, PlayerController invalid!");
		return false;
	}
	
	return true;
}

bool ATurnBasedGameModeBase::InitializeUI()
{
	HUD = Cast<ATurnBasedHUDBase>(PlayerController->GetHUD());
	
	if (!IsValid(HUD))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameModeBase] Failed init, HUD invalid!");
		return false;
	}
	
	HUD->InitializeHUD();
	
	return true;
}

void ATurnBasedGameModeBase::StartGame()
{
	
}
