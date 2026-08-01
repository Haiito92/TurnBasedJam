// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionContext.generated.h"

/**
 * 
 */


class UAction;
class ATurnBasedActor;

USTRUCT(BlueprintType)
struct TURNBASEDJAM_API FActionContext
{
	GENERATED_BODY()
	
public:
	FActionContext() = default;
	~FActionContext() = default;
	
	UPROPERTY()
	TObjectPtr<UAction> Action;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Caster;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Target;
};
