// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/TurnMechanic/TurnBasedActor.h"

#include "Logic/Actions/ActionSolver.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"


// Sets default values
ATurnBasedActor::ATurnBasedActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
	SetRootComponent(ActorMesh);
}

void ATurnBasedActor::PrepareTurn(ATurnBasedActor* Enemy)
{
}

void ATurnBasedActor::SetNextActionData(UActionData* Data)
{
	NextAction.Data = Data;
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
	if (NextAction.Data == nullptr)
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[ATurnBasedActor] Validating nullptr action data.");
		return;
	}
	
	NextActionValidated.Broadcast(NextAction.Data);
}

void ATurnBasedActor::FinalizeTurnPreparation()
{
	TurnPreparationFinalized.Broadcast();
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

TArray<UActionData*> ATurnBasedActor::GetActionsData() const
{
	return ActionsData;
}

FAction ATurnBasedActor::GetNextAction() const
{
	return NextAction;
}


