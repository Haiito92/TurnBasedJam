// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status.h"
#include "Components/ActorComponent.h"
#include "StatusComponent.generated.h"


class UStatus;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TURNBASEDJAM_API UStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStatusComponent();

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="StatusClass"))
	bool ApplyStatus(const TSubclassOf<UStatus>& StatusClass, UStatus* InOutStatus);
	
	UFUNCTION(BlueprintCallable)
	void TickStatus(TArray<UStatus*> StatusList);
	
	UFUNCTION(BlueprintCallable)
	bool RemoveStatus(UStatus* Status);
	
	UFUNCTION(BlueprintCallable)
	void RemoveAllStatusByEnum(const EStatusEnum& StatusEnum, TArray<UStatus*>& InOutStatusRemoved);
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="StatusEnum"))
	bool HasStatus(const EStatusEnum& StatusEnum) const;
	
	UFUNCTION(BlueprintCallable)
	const TArray<UStatus*>& GetAllAppliedStatus() const;
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Group"))
	TArray<UStatus*> GetAppliedStatusByGroup(const EStatusGroup& Group) const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(AutoCreateRefTerm="StatusEnum"))
	UStatus* GetFirstAppliedStatusByEnum(const EStatusEnum& StatusEnum);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(AutoCreateRefTerm="StatusEnum"))
	TArray<UStatus*> GetAllAppliedStatusByEnum(const EStatusEnum& StatusEnum);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatusChangedSignature, const TArray<UStatus*>&, StatusList);
	UPROPERTY(BlueprintAssignable)
	FStatusChangedSignature StatusChanged;

protected:
	
	UPROPERTY(BlueprintReadOnly)
	TArray<TObjectPtr<UStatus>> AppliedStatus;
};
