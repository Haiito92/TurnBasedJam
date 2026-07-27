// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/GameModes/TurnBasedGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/FightActors/Hero.h"
#include "Logic/FightActors/Vampire.h"
#include "Logic/GameModes/GameModesSettings.h"
#include "Logic/PlayerControllers/TurnBasedPlayerControllerBase.h"
#include "Logic/TurnMechanic/TurnManager.h"

AHero* ATurnBasedGameMode::GetHero() const
{
	return Hero;
}

AVampire* ATurnBasedGameMode::GetVampire() const
{
	return Vampire;
}

bool ATurnBasedGameMode::InitializeGame()
{
	if (!Super::InitializeGame()) return false;

	Hero = Cast<AHero>(UGameplayStatics::GetActorOfClass(this, AHero::StaticClass()));
	
	if (!IsValid(Hero))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameMode] Failed init, invalid Hero.");
		return false;
	}
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameMode] Hero valid!");
	
	Vampire = Cast<AVampire>(UGameplayStatics::GetActorOfClass(this, AVampire::StaticClass()));
	if (!IsValid(Vampire))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameMode] Failed init, invalid Vampire.");
		return false;
	}
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameMode] Vampire valid!");

	TurnManager = NewObject<UTurnManager>(this, GameModesSettings->TurnManagerClass.LoadSynchronous());
	
	if (!IsValid(TurnManager))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameMode] Failed init, invalid TurnManager.");
		return false;
	}
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameMode] TurnManager valid!");
	
	if (!TurnManager->InitializeTurnManager(Hero, Vampire))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedGameMode] Failed init, TurnManager init failed.");
		return false;
	}
	
	return true;
}

void ATurnBasedGameMode::StartGame()
{
	Super::StartGame();
	
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[ATurnBasedGameMode] Start Game!");

	FInputModeUIOnly InputModeData = {};
	PlayerController->SetInputMode(InputModeData);
	PlayerController->SetShowMouseCursor(true);
	
	TurnManager->StartFight();
}
