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
	
	switch (Status->GetDuplicity())
	{
	case EStatusDuplicity::None:
			{
				break;		
			}
	case EStatusDuplicity::Solo:
		{
			if (HasStatus(Status->GetEnum()))
			{
				//UTurnBasedDebugLibrary::Print(EDebugMessageType::Warning, "[UStatusComponent] Can't apply solo status already applied: " + StatusClass->GetName());
		
				UStatus* SoloStatus = GetFirstAppliedStatusByEnum(Status->GetEnum());
				SoloStatus->ResetStatus();
				InOutStatus = SoloStatus;
				break;
			}
			
			Status->InitStatus();
			AppliedStatus.Add(Status);
			InOutStatus = Status;
			
			FirstStatusCopyApplied.Broadcast(Status->GetEnum());
			
			DidApplyStatus = true;
			break;
		}
	case EStatusDuplicity::Multiple:
		{
			if (!HasStatus(Status->GetEnum()))
			{
				FirstStatusCopyApplied.Broadcast(Status->GetEnum());
			}
			
			Status->InitStatus();
			AppliedStatus.Add(Status);
			InOutStatus = Status;
		
			DidApplyStatus = true;
			break;
		}
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
	
	if (!HasStatus(Status->GetEnum()))
	{
		LastStatusCopyRemoved.Broadcast(Status->GetEnum());
	}
	return true;
}

void UStatusComponent::RemoveAllStatusByEnum(const EStatusEnum& StatusEnum, TArray<UStatus*>& InOutStatusRemoved)
{
	InOutStatusRemoved.Empty();
	
	for (UStatus* Status : AppliedStatus)
	{
		if (Status->GetEnum() == StatusEnum) InOutStatusRemoved.Add(Status);
	}
	
	for (UStatus* Status : InOutStatusRemoved)
	{
		AppliedStatus.Remove(Status);
	}
	
	LastStatusCopyRemoved.Broadcast(StatusEnum);
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

TArray<UStatus*> UStatusComponent::GetAllAppliedStatusByEnum(const EStatusEnum& StatusEnum)
{
	TArray<UStatus*> StatusToReturn;
	
	for (UStatus* Status : AppliedStatus)
	{
		if (Status->GetEnum() == StatusEnum) StatusToReturn.Add(Status);
	}
	
	return StatusToReturn;
}

