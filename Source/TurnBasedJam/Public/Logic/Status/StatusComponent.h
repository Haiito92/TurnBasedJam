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
	void ApplyStatus(const TSubclassOf<UStatus>& StatusClass);
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="StatusClass"))
	void RemoveStatus(const TSubclassOf<UStatus>& StatusClass);
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="StatusEnum"))
	bool HasStatus(const EStatusEnum& StatusEnum) const;
	
	UFUNCTION(BlueprintCallable)
	const TArray<UStatus*>& GetAllAppliedStatus() const;
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Group"))
	TArray<UStatus*> GetAppliedStatusByGroup(const EStatusGroup& Group) const;
	
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="StatusEnum"))
	const UStatus* GetFirstAppliedStatusByEnum(const EStatusEnum& StatusEnum) const;
protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<TObjectPtr<UStatus>> AppliedStatus;
};
