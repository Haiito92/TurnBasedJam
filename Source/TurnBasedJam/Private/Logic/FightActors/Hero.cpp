// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/FightActors/Hero.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"


// Sets default values
AHero::AHero()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AHero::ChooseNextAction_Implementation()
{
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[Hero] Action chosen!");
	
	Super::ChooseNextAction_Implementation();
}

