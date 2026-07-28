// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TurnBasedHUDBase.generated.h"

/**
 * 
 */

UCLASS()
class TURNBASEDJAM_API ATurnBasedHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void InitializeHUD();
	
	UFUNCTION()
	void StartHUD();
	
protected:
	UFUNCTION()
	virtual void InternalInitialization();
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive Internal Initialization")
	void ReceiveInternalInitialization();

	UFUNCTION()
	virtual void SpawnWidgets();
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive Spawn Widgets")
	void ReceiveSpawnWidgets();
	
	UFUNCTION()
	virtual void InitializeWidgets();
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive Initialize Widgets")
	void ReceiveInitializeWidgets();
	
	UFUNCTION()
	virtual void InternalStart();
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive Internal Start")
	void ReceiveInternalStart();
	
	UFUNCTION()
	virtual void StartWidgets();
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Receive Start Widgets")
	void ReceiveStartWidgets();
};
