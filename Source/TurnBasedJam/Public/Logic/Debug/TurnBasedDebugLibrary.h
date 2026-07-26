// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TurnBasedDebugLibrary.generated.h"

/**
 * 
 */
UENUM()
enum class EDebugMessageType : uint8
{
	Log,
	Warning,
	Error,
};

UCLASS()
class TURNBASEDJAM_API UTurnBasedDebugLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static void ToggleDebug(bool InDebugOn);
	static void Print(const EDebugMessageType& MessageType, const FString& Message, float TimeToDisplay = 3.0f);
private:
	static bool DebugOn;	
};
