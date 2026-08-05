// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurnBasedGameModeBase.h"
#include "TurnBasedGameMode.generated.h"

class UDialogueWorldSubsystem;
class UDialogueData;
class AVampire;
class AHero;
class UTurnManager;
/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API ATurnBasedGameMode : public ATurnBasedGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	AHero* GetHero() const;
	UFUNCTION(BlueprintCallable)
	AVampire* GetVampire() const;
	
protected:
	
	virtual bool InitializeGame() override;
	virtual void StartGame() override;
	virtual void EndGame(bool Won) override;
	
	UFUNCTION()
	void OnDialogueStarted(const UDialogueData* DialogueData);
	UFUNCTION()
	void OnDialogueEnded(const UDialogueData* DialogueData);
	UFUNCTION()
	void OnFightEnded(bool bHeroWon);
private:
	UPROPERTY()
	TObjectPtr<UTurnManager> TurnManager;
	
	UPROPERTY()
	TObjectPtr<AHero> Hero;
	
	UPROPERTY()
	TObjectPtr<AVampire> Vampire;
	
	UPROPERTY()
	TObjectPtr<UDialogueWorldSubsystem> DialogueWorldSubsystem;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UDialogueData> StartDialogue;
};
