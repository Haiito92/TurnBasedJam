// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/TurnMechanic/TurnBasedActor.h"

#include "Logic/Actions/Action.h"
#include "Logic/Actions/ActionData.h"
#include "Logic/Actions/ActionSolver.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/Health/HealthComponent.h"
#include "Logic/Status/StatusComponent.h"


// Sets default values
ATurnBasedActor::ATurnBasedActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
	SetRootComponent(ActorMesh);
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	StatusComponent = CreateDefaultSubobject<UStatusComponent>("StatusComponent");
}

void ATurnBasedActor::InitTurnBasedActor()
{
	Actions.Empty();
	
	for (const TSubclassOf<UAction>& ActionClass : ActionClasses)
	{
		UAction* Action = NewObject<UAction>(this, ActionClass);
		
		if (!IsValid(Action))
		{
			continue;
		}
		
		Actions.Add(Action);
	}
	
	if (IsValid(HealthComponent))
	{
		HealthComponent->InitHealthComponent();
	}
	else UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedActor] Failed to fully init, health component invalid!");
}

void ATurnBasedActor::PrepareTurn(ATurnBasedActor* Enemy)
{
}

void ATurnBasedActor::SetNextAction(UAction* InAction)
{
	NextAction.Action = InAction;
}

void ATurnBasedActor::SetNextActionCaster(ATurnBasedActor* Caster)
{
	NextAction.Caster = Caster;
}

void ATurnBasedActor::SetNextActionTarget(ATurnBasedActor* Target)
{
	NextAction.Target = Target;
}

void ATurnBasedActor::ValidateNextAction()
{
	if (NextAction.Action == nullptr)
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedActor] Validating nullptr action data.");
		return;
	}
	
	NextActionValidated.Broadcast(NextAction.Action);
}

void ATurnBasedActor::FinalizeTurnPreparation()
{
	TurnPreparationFinalized.Broadcast();
}

void ATurnBasedActor::PlayNextActionAnim()
{
	if (!IsValid(NextAction.Action) || !IsValid(NextAction.Action->GetActionData())) return;
	ReceivePlayNextActionAnim(NextAction.Action->GetActionData()->Type);
}


void ATurnBasedActor::StartTurn()
{
	TurnStarted.Broadcast();
	
	UActionSolverLibrary::SolveAction(NextAction);
	
	EndTurn();
}

void ATurnBasedActor::EndTurn()
{
	TurnEnded.Broadcast();
}

const TArray<UAction*>& ATurnBasedActor::GetActions() const
{
	return Actions;
}

FActionContext ATurnBasedActor::GetNextAction() const
{
	return NextAction;
}

UHealthComponent* ATurnBasedActor::GetHealthComponent()
{
	return HealthComponent;
}

UStatusComponent* ATurnBasedActor::GetStatusComponent()
{
	return StatusComponent;
}


