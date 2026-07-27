// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logic/TurnMechanic/TurnBasedActor.h"
#include "Hero.generated.h"

UCLASS()
class TURNBASEDJAM_API AHero : public ATurnBasedActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHero();
	
	virtual void ChooseNextAction_Implementation() override;
};
