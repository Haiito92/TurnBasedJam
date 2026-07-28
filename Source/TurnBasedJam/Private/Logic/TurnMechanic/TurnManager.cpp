// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/TurnMechanic/TurnManager.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/TurnMechanic/TurnBasedActor.h"

bool UTurnManager::InitializeTurnManager(ATurnBasedActor* InHero, ATurnBasedActor* InVampire)
{
	Hero = InHero;
	if (!IsValid(Hero))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UTurnManager] Init failed, hero invalid!");
		return false;
	}
	Hero->NextActionValidated.AddDynamic(this, &UTurnManager::OnHeroNextActionValidated);
	
	Vampire = InVampire;
	if (!IsValid(Vampire))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UTurnManager] Init failed, vampire invalid!");
		return false;
	}
	
	return true;
}

void UTurnManager::StartFight()
{
	if (!IsValid(Vampire) || !IsValid(Hero))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UTurnManager] Can't start fight, vampire or hero invalid!");
		return;
	}
	
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[UTurnManager] Start Fight!");
	
	PrepareTurn();
}

void UTurnManager::PrepareTurn()
{
	Vampire->PrepareTurn(Hero);
	
	Hero->PrepareTurn(Vampire);
}

void UTurnManager::OnHeroNextActionValidated(UActionData* ActionValidatedData)
{
	FinalizeTurnPreparation();
}

void UTurnManager::FinalizeTurnPreparation()
{
	Hero->FinalizeTurnPreparation();
	Vampire->FinalizeTurnPreparation();
	
	ResolveTurn();
}

void UTurnManager::ResolveTurn()
{
	GetWorld()->GetTimerManager().SetTimer(
		TurnResolutionEndTimer,
		this,
		&UTurnManager::OnTurnResolutionEndTimerElapsed,
		5.0f,
		false);
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Warning, "[UTurnManager] Wait for next turn preparation in 5 seconds...");
}

void UTurnManager::OnTurnResolutionEndTimerElapsed()
{
	PrepareTurn();
}
