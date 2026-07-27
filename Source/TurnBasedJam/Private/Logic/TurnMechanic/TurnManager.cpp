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
	Hero->NextActionChosen.AddDynamic(this, &UTurnManager::OnHeroNextActionChosen);
	
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
	ITurnBased::Execute_PrepareTurn(Vampire);
	
	ITurnBased::Execute_PrepareTurn(Hero);
}

void UTurnManager::OnHeroNextActionChosen()
{
	FinalizeTurnPreparation();
}

void UTurnManager::FinalizeTurnPreparation()
{
	ITurnBased::Execute_FinalizeTurnPreparation(Hero);
	ITurnBased::Execute_FinalizeTurnPreparation(Vampire);
	
	ResolveTurn();
}

void UTurnManager::ResolveTurn()
{
	
}
