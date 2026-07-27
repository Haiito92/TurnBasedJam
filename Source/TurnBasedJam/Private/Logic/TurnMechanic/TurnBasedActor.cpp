// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/TurnMechanic/TurnBasedActor.h"


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

void ATurnBasedActor::SetNextActionTarget(ATurnBasedActor* Target)
{
	NextAction.Target = Target;
}

void ATurnBasedActor::ValidateNextAction()
{
	NextActionValidated.Broadcast();
}

void ATurnBasedActor::FinalizeTurnPreparation()
{
}

void ATurnBasedActor::StartTurn()
{
	TurnStarted.Broadcast();
}

void ATurnBasedActor::EndTurn()
{
	TurnEnded.Broadcast();
}

TArray<UActionData*> ATurnBasedActor::GetActionsData() const
{
	return ActionsData;
}


