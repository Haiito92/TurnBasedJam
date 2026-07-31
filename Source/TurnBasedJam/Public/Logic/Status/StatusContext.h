// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StatusContext.generated.h"

class UStatus;
class ATurnBasedActor;
/**
 * 
 */
USTRUCT(BlueprintType)
struct TURNBASEDJAM_API FStatusContext
{
	GENERATED_BODY()
	
public:
	FStatusContext() = default;
	~FStatusContext() = default;
	
	UPROPERTY()
	TArray<TObjectPtr<UStatus>> StatusArray;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Target;
};
