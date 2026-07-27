// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/FightActors/Hero.h"


// Sets default values
AHero::AHero()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AHero::PrepareTurn(ATurnBasedActor* Enemy)
{
	SetNextActionTarget(this); // All hero action target himself so I'm just doing this, faster even if not clean
	
	TurnPreparationStarted.Broadcast();
}

