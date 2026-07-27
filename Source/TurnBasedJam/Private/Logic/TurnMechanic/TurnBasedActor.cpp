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

void ATurnBasedActor::PrepareTurn_Implementation()
{
	ITurnBased::PrepareTurn_Implementation();
}

void ATurnBasedActor::FinalizeTurnPreparation_Implementation()
{
	ITurnBased::FinalizeTurnPreparation_Implementation();
}

void ATurnBasedActor::ChooseNextAction_Implementation()
{
	ITurnBased::ChooseNextAction_Implementation();
	
	NextActionChosen.Broadcast();
}


void ATurnBasedActor::StartTurn_Implementation()
{
	ITurnBased::StartTurn_Implementation();
	
	TurnStarted.Broadcast();
}

void ATurnBasedActor::EndTurn_Implementation()
{
	ITurnBased::EndTurn_Implementation();
	
	TurnEnded.Broadcast();
}


