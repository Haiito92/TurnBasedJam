// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Action.generated.h"

class UStatus;
class UActionData;
class ATurnBasedActor;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class TURNBASEDJAM_API UAction : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool ApplyActionStrategy(ATurnBasedActor* ActionTarget);
	
	UFUNCTION(BlueprintCallable)
	UActionData* GetActionData() const;
	
	UFUNCTION(BlueprintCallable)
	const TArray<TSubclassOf<UStatus>>& GetStatusClassesToApply() const;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UActionData> Data;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UStatus>> StatusClassesToApply;
};
