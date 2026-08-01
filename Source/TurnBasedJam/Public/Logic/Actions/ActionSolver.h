// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActionSolver.generated.h"

struct FActionContext;
/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UActionSolverLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static void SolveAction(const FActionContext& ActionContext);
};
