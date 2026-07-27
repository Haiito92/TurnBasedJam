// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TurnBased.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UTurnBased : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TURNBASEDJAM_API ITurnBased
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent)
	void PrepareTurn();
	
	UFUNCTION(BlueprintNativeEvent)
	void FinalizeTurnPreparation();
	
	UFUNCTION(BlueprintNativeEvent)
	void ChooseNextAction();
	
	UFUNCTION(BlueprintNativeEvent)
	void StartTurn();
	
	UFUNCTION(BlueprintNativeEvent)
	void EndTurn();
};
