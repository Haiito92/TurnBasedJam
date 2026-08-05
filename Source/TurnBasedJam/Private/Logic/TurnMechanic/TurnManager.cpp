// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/TurnMechanic/TurnManager.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/Status/StatusSolver.h"
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
	Hero->TurnEnded.AddDynamic(this, &UTurnManager::OnHeroTurnEnded);
	
	Vampire = InVampire;
	if (!IsValid(Vampire))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UTurnManager] Init failed, vampire invalid!");
		return false;
	}
	Vampire->TurnEnded.AddDynamic(this, &UTurnManager::OnVampireTurnEnded);
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

void UTurnManager::EndFight(bool HeroWon)
{
	FightEnded.Broadcast(HeroWon);
}

void UTurnManager::PrepareTurn()
{
	UStatusSolver::TickStatus({EStatusGroup::GlobalStartTurn, Hero});
	UStatusSolver::TickStatus({EStatusGroup::GlobalStartTurn, Vampire});
	
	UStatusSolver::PurgeStatus({EStatusGroup::GlobalStartTurn, Hero});
	UStatusSolver::PurgeStatus({EStatusGroup::GlobalStartTurn, Vampire});
	
	Vampire->PrepareTurn(Hero);
	
	Hero->PrepareTurn(Vampire);
}

void UTurnManager::OnHeroNextActionValidated(UAction* ActionValidatedData)
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
	UStatusSolver::TickStatus({EStatusGroup::ActorStartTurn, Hero});
	UStatusSolver::PurgeStatus({EStatusGroup::ActorStartTurn, Hero});
	Hero->StartTurn();
}

void UTurnManager::OnHeroTurnEnded()
{
	UStatusSolver::TickStatus({EStatusGroup::ActorEndTurn, Hero});
	UStatusSolver::PurgeStatus({EStatusGroup::ActorEndTurn, Hero});
	
	UStatusSolver::TickStatus({EStatusGroup::ActorStartTurn, Vampire});
	UStatusSolver::PurgeStatus({EStatusGroup::ActorStartTurn, Vampire});
	Vampire->StartTurn();
}

void UTurnManager::OnVampireTurnEnded()
{
	UStatusSolver::TickStatus({EStatusGroup::ActorEndTurn, Vampire});
	UStatusSolver::PurgeStatus({EStatusGroup::ActorEndTurn, Vampire});
	
	UStatusSolver::TickStatus({EStatusGroup::GlobalEndTurn, Hero});
	UStatusSolver::TickStatus({EStatusGroup::GlobalEndTurn, Vampire});
	
	UStatusSolver::PurgeStatus({EStatusGroup::GlobalEndTurn, Hero});
	UStatusSolver::PurgeStatus({EStatusGroup::GlobalEndTurn, Vampire});
	
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
	if (!Hero->GetHealthComponent()->IsAlive())
	{
		EndFight(false);
		return;
	}	
	
	if (!Vampire->GetHealthComponent()->IsAlive())
	{
		EndFight(true);
		return;	
	}
	
	PrepareTurn();
}
