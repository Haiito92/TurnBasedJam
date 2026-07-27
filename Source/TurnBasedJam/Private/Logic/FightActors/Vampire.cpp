// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/FightActors/Vampire.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"


// Sets default values
AVampire::AVampire()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AVampire::PrepareTurn_Implementation()
{
	Super::PrepareTurn_Implementation();
	
	Execute_ChooseNextAction(this);
}

void AVampire::ChooseNextAction_Implementation()
{
	Super::ChooseNextAction_Implementation();
	
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[Vampire] Action chosen!");
}

