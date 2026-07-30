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

UCLASS()
class TURNBASEDJAM_API UStatus : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	EStatusEnum Enum = EStatusEnum::ST_None;
	
	UPROPERTY()
	int Lifespan = 1;
	
	UPROPERTY()
	EStatusGroup Group = EStatusGroup::GlobalStartTurn;
	
	UFUNCTION(BlueprintCallable)
	virtual void ApplyStatus(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable)
	virtual void TickStatus(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable)
	virtual void RemoveStatus(ATurnBasedActor* Target);
};
