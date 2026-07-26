// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameModesSettings.generated.h"

class UTurnManager;
/**
 * 
 */
UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="GameModes Settings"))
class TURNBASEDJAM_API UGameModesSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Turn Based GameMode")
	TSoftClassPtr<UTurnManager> TurnManagerClass;
};
