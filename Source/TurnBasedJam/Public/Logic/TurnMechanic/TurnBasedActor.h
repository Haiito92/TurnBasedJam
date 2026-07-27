// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurnBased.h"
#include "GameFramework/Actor.h"
#include "TurnBasedActor.generated.h"

UCLASS()
class TURNBASEDJAM_API ATurnBasedActor : public AActor, public ITurnBased
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurnBasedActor();

	virtual void StartTurn_Implementation() override;
	
	virtual void EndTurn_Implementation() override;	
};
