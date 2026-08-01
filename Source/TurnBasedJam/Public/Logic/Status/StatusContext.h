// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status.h"
#include "UObject/Object.h"
#include "StatusContext.generated.h"

class UStatus;
class ATurnBasedActor;
/**
 * 
 */
USTRUCT(BlueprintType)
struct TURNBASEDJAM_API FApplyStatusContext
{
	GENERATED_BODY()
	
public:
	FApplyStatusContext() = default;
	FApplyStatusContext(const TSubclassOf<UStatus>& InStatusClass, ATurnBasedActor* InTarget);
	~FApplyStatusContext() = default;
	
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UStatus> StatusClass;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ATurnBasedActor> Target;
};

USTRUCT(BlueprintType)
struct TURNBASEDJAM_API FTickMultipleStatusContext
{
	GENERATED_BODY()
	
public:
	FTickMultipleStatusContext() = default;
	FTickMultipleStatusContext(const EStatusGroup& InGroup, ATurnBasedActor* InHolder);
	~FTickMultipleStatusContext() = default;
	
	UPROPERTY(BlueprintReadWrite)
	EStatusGroup Group;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ATurnBasedActor> Holder;
};

USTRUCT(BlueprintType)
struct TURNBASEDJAM_API FRemoveStatusContext
{
	GENERATED_BODY()
	
public:
	FRemoveStatusContext() = default;
	FRemoveStatusContext(UStatus* InStatus, ATurnBasedActor* InHolder);
	~FRemoveStatusContext() = default;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UStatus> Status;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ATurnBasedActor> Holder;
};

USTRUCT(BlueprintType)
struct TURNBASEDJAM_API FPurgeStatusContext
{
	GENERATED_BODY()
	
public:
	FPurgeStatusContext() = default;
	FPurgeStatusContext(const EStatusGroup& InGroup, ATurnBasedActor* InHolder);
	~FPurgeStatusContext() = default;
	
	UPROPERTY(BlueprintReadWrite)
	EStatusGroup Group;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ATurnBasedActor> Holder;
};
