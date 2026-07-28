// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Action.generated.h"

/**
 * 
 */


class ATurnBasedActor;
class UActionData;

USTRUCT()
struct TURNBASEDJAM_API FAction
{
	GENERATED_BODY()
	
public:
	FAction() = default;
	~FAction() = default;
	
	UPROPERTY()
	TObjectPtr<UActionData> Data;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Caster;
	
	UPROPERTY()
	TObjectPtr<ATurnBasedActor> Target;
};
