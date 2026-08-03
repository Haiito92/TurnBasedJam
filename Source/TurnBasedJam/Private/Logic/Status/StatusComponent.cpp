// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Status/StatusComponent.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"


// Sets default values for this component's properties
UStatusComponent::UStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

bool UStatusComponent::ApplyStatus(const TSubclassOf<UStatus>& StatusClass, UStatus* InOutStatus)
{
	UStatus* Status = NewObject<UStatus>(this, StatusClass);
	
	bool DidApplyStatus	= false;
	if (HasStatus(Status->GetEnum()) && Status->GetDuplicity() == EStatusDuplicity::Solo)
	{
		//UTurnBasedDebugLibrary::Print(EDebugMessageType::Warning, "[UStatusComponent] Can't apply solo status already applied: " + StatusClass->GetName());
		
		UStatus* SoloStatus = GetFirstAppliedStatusByEnum(Status->GetEnum());
		SoloStatus->ResetStatus();
		InOutStatus = SoloStatus;
	}
	else
	{
		AppliedStatus.Add(Status);
		InOutStatus = Status;
		
		DidApplyStatus = true;
	}
	
	StatusChanged.Broadcast(AppliedStatus);
	return DidApplyStatus;
}

void UStatusComponent::TickStatus(TArray<UStatus*> StatusList)
{
	StatusChanged.Broadcast(AppliedStatus);
}

bool UStatusComponent::RemoveStatus(UStatus* Status)
{
	TArray<TObjectPtr<UStatus>>::SizeType NbRemoved = AppliedStatus.Remove(Status);
	
	if (NbRemoved == 0) return false;
	
	StatusChanged.Broadcast(AppliedStatus);
	return true;
}



bool UStatusComponent::HasStatus(const EStatusEnum& StatusEnum) const
{
	for (UStatus* Status : AppliedStatus)
	{
		if (Status->GetEnum() == StatusEnum) return true;
	}
	
	return false;
}

const TArray<UStatus*>& UStatusComponent::GetAllAppliedStatus() const
{
	return AppliedStatus;
}

TArray<UStatus*> UStatusComponent::GetAppliedStatusByGroup(const EStatusGroup& Group) const
{
	TArray<UStatus*> StatusToReturn;
	
	for (UStatus* Status : AppliedStatus)
	{
		if (Status->GetGroup() == Group) StatusToReturn.Add(Status);
	}
	
	return StatusToReturn;
}

UStatus* UStatusComponent::GetFirstAppliedStatusByEnum(const EStatusEnum& StatusEnum)
{
	UStatus* FoundStatus = AppliedStatus.FindByPredicate([&](const UStatus* Status)
	{
		return Status->GetEnum() == StatusEnum;
	})->Get();
	
	return FoundStatus;
}

