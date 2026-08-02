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
	GlobalStartTurn,
	GlobalEndTurn,
	ActorStartTurn,
	ActorEndTurn
};

UENUM()
enum class EStatusDuplicity: uint8
{
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
	const EStatusEnum& GetEnum() const;
	UFUNCTION(BlueprintCallable)
	const EStatusDuplicity& GetDuplicity() const;
	UFUNCTION(BlueprintCallable)
	float GetOriginalLifespan() const;
	UFUNCTION(BlueprintCallable)
	float GetCurrentLifespan() const;
	UFUNCTION(BlueprintCallable)
	const EStatusGroup& GetGroup() const;
	
	UFUNCTION(BlueprintCallable)
	const UStatusData* GetData() const;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
	EStatusEnum Enum = EStatusEnum::ST_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
	EStatusDuplicity Duplicity = EStatusDuplicity::Solo;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
	int OriginalLifespan = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
	EStatusGroup Group = EStatusGroup::GlobalStartTurn;
	
private:
	UPROPERTY()
	int CurrentLifespan;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStatusData> Data;
};
