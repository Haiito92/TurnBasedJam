// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TurnBasedGameModeBase.generated.h"

class ATurnBasedHUDBase;
class UGameModesSettings;
/**
 * 
 */



UCLASS()
class TURNBASEDJAM_API ATurnBasedGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
	bool InitializeGameMode();
	virtual bool InitializeGame();
	virtual bool InitializeUI();
	virtual void StartGame();
	
	UPROPERTY()
	const UGameModesSettings* GameModesSettings;
	
private:
	UPROPERTY()
	TObjectPtr<ATurnBasedHUDBase> HUD;
};
