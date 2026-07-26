// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "TurnBasedCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UTurnBasedCheatManager : public UCheatManager
{
	GENERATED_BODY()
	
private:
	UFUNCTION(Exec)
	void ToggleDebug(bool DebugOn);
};
