// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatusContext.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StatusSolver.generated.h"

/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UStatusSolver : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="StatusContext"))
	static void ApplyStatus(const FApplyStatusContext& StatusContext);
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Context"))
	static void TickStatus(const FTickMultipleStatusContext& Context);
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Context"))
	static void RemoveStatus(const FRemoveStatusContext& Context);
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Context"))
	static void PurgeStatus(const FPurgeStatusContext& Context);
};
