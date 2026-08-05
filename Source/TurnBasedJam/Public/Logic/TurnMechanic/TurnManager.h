// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TurnManager.generated.h"

class UAction;
class UActionSolver;
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
	
	UFUNCTION()
	void EndFight(bool HeroWon);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFightEndedSignature, bool, HeroWon);
	UPROPERTY(BlueprintAssignable)
	FFightEndedSignature FightEnded;
	
private:
	UFUNCTION()
	void PrepareTurn();
	UFUNCTION()
	void OnHeroNextActionValidated(UAction* ActionValidatedData);
	UFUNCTION()
	void FinalizeTurnPreparation();
	UFUNCTION()
	void ResolveTurn();
	
	UFUNCTION()
	void OnHeroTurnEnded();
	UFUNCTION()
	void OnVampireTurnEnded();
	
	void OnTurnResolutionEndTimerElapsed();
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Hero;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Vampire;
	
	UPROPERTY()
	FTimerHandle TurnResolutionEndTimer;
};
