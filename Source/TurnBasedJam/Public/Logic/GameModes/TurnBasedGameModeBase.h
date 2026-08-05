// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TurnBasedGameModeBase.generated.h"

class UUIEventsHolder;
class ATurnBasedPlayerControllerBase;
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
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveInitializeGame();
	
	virtual bool InitializeUI();
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveInitializeUI();
	
	virtual void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveStartGame();
	
	
	virtual void EndGame(bool Won);
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveEndGame(bool Won);
	
	UPROPERTY(BlueprintReadOnly)
	const UGameModesSettings* GameModesSettings;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ATurnBasedHUDBase> HUD;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ATurnBasedPlayerControllerBase> PlayerController;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUIEventsHolder> UIEventsHolder;
};
