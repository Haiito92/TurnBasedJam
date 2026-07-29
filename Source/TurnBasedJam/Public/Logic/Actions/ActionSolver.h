// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionSolver.generated.h"

struct FAction;
/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UActionSolverLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static void SolveAction(const FAction& Action);
};
