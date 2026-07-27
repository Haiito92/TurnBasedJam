// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/FightActors/Vampire.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"


// Sets default values
AVampire::AVampire()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AVampire::PrepareTurn(ATurnBasedActor* Enemy)
{
	TurnPreparationStarted.Broadcast();
	
	SetNextActionTarget(Enemy);
	
	//Action choice
	
	ValidateNextAction();
}

