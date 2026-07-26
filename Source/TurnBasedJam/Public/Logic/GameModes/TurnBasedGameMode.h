// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurnBasedGameModeBase.h"
#include "TurnBasedGameMode.generated.h"

class UTurnManager;
/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API ATurnBasedGameMode : public ATurnBasedGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void InitializeGameMode() override;
private:
	UPROPERTY()
	TObjectPtr<UTurnManager> TurnManager;
};
