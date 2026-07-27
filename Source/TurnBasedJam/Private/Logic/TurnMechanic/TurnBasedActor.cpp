// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/TurnMechanic/TurnBasedActor.h"


// Sets default values
ATurnBasedActor::ATurnBasedActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATurnBasedActor::StartTurn_Implementation()
{
	ITurnBased::StartTurn_Implementation();
}

void ATurnBasedActor::EndTurn_Implementation()
{
	ITurnBased::EndTurn_Implementation();
}


