// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TurnManager.generated.h"

class ATurnBasedActor;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TURNBASEDJAM_API UTurnManager : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	bool InitializeTurnManager(ATurnBasedActor* InHero, ATurnBasedActor* InVampire);
	
	UFUNCTION()
	void StartFight();
	
private:
	UFUNCTION()
	void PrepareTurn();
	UFUNCTION()
	void OnHeroNextActionChosen();
	UFUNCTION()
	void FinalizeTurnPreparation();
	UFUNCTION()
	void ResolveTurn();
	
	void OnTurnResolutionEndTimerElapsed();
	
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Hero;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Vampire;
	
	UPROPERTY()
	FTimerHandle TurnResolutionEndTimer;
};
