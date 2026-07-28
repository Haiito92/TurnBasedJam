// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logic/TurnMechanic/TurnBasedActor.h"
#include "Vampire.generated.h"

UCLASS()
class TURNBASEDJAM_API AVampire : public ATurnBasedActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVampire();
	
	virtual void PrepareTurn(ATurnBasedActor* Enemy) override;
	
private:
	UPROPERTY()
	UActionData* LastActionData;
};
