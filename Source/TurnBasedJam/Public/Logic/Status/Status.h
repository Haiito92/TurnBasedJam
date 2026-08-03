// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatusEnum.h"
#include "UObject/Object.h"
#include "Status.generated.h"

/**
 * 
 */

class UStatusData;
class ATurnBasedActor;

UENUM()
enum class EStatusGroup: uint8
{
	None,
	GlobalStartTurn,
	GlobalEndTurn,
	ActorStartTurn,
	ActorEndTurn
};

UENUM()
enum class EStatusDuplicity: uint8
{
	None,
	Solo,
	Multiple
};

UCLASS(Blueprintable, BlueprintType)
class TURNBASEDJAM_API UStatus : public UObject
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable)
	void InitStatus();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ApplyStatus(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TickStatus(ATurnBasedActor* Target);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveStatus(ATurnBasedActor* Target);
	
	UFUNCTION(BlueprintCallable)
	void ResetStatus();
	
	UFUNCTION(BlueprintCallable)
	EStatusEnum GetEnum() const;
	UFUNCTION(BlueprintCallable)
	EStatusDuplicity GetDuplicity() const;
	UFUNCTION(BlueprintCallable)
	float GetOriginalLifespan() const;
	UFUNCTION(BlueprintCallable)
	float GetCurrentLifespan() const;
	UFUNCTION(BlueprintCallable)
	EStatusGroup GetGroup() const;
	
	UFUNCTION(BlueprintCallable)
	const UStatusData* GetData() const;
	
protected:
	
	
private:
	UPROPERTY()
	int CurrentLifespan;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStatusData> Data;
};
