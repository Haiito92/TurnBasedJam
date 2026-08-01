// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatusEnum.h"
#include "UObject/Object.h"
#include "Status.generated.h"

/**
 * 
 */

class ATurnBasedActor;

UENUM()
enum class EStatusGroup: uint8
{
	GlobalStartTurn,
	GlobalEndTurn,
	ActorStartTurn,
	ActorEndTurn
};

UCLASS(Blueprintable, BlueprintType)
class TURNBASEDJAM_API UStatus : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Status")
	EStatusEnum Enum = EStatusEnum::ST_None;
	
	UPROPERTY(EditAnywhere, Category="Status")
	int Lifespan = 1;
	
	UPROPERTY(EditAnywhere, Category="Status")
	EStatusGroup Group = EStatusGroup::GlobalStartTurn;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ApplyStatus(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TickStatus(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveStatus(ATurnBasedActor* Target);
};
