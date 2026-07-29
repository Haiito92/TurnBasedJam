// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatusEnum.h"
#include "UObject/Object.h"
#include "Status.generated.h"

/**
 * 
 */

UENUM()
enum class EStatusGroup: uint8
{
	GlobalStartTurn,
	GlobalEndTurn,
	ActorStartTurn,
	ActorEndTurn
};

USTRUCT()
struct TURNBASEDJAM_API FStatus
{
	GENERATED_BODY()
	
public:
	FStatus() = default;
	~FStatus() = default;

	UPROPERTY()
	EStatusEnum Enum = EStatusEnum::ST_None;
	
	UPROPERTY()
	int Lifespan = 1;
	
	UPROPERTY()
	EStatusGroup Group = EStatusGroup::GlobalStartTurn;
};
