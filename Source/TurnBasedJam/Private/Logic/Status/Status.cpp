// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Status/Status.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/Status/StatusData.h"

void UStatus::ApplyStatus_Implementation(ATurnBasedActor* Target)
{
}

void UStatus::TickStatus_Implementation(ATurnBasedActor* Target)
{
	CurrentLifespan--;
}

void UStatus::RemoveStatus_Implementation(ATurnBasedActor* Target)
{
}

void UStatus::InitStatus()
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatus] Can't init, data invalid!");
		return;
	}
	
	CurrentLifespan = Data->OriginalLifespan;
}

void UStatus::ResetStatus()
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatus] Can't reset, data invalid!");
		return;
	}
	
	CurrentLifespan = Data->OriginalLifespan;
}

EStatusEnum UStatus::GetEnum() const
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatus] Can't get enum, data invalid!");
		return EStatusEnum::ST_None;
	}
	return Data->Enum;
}

EStatusDuplicity UStatus::GetDuplicity() const
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatus] Can't get duplicity, data invalid!");
		return EStatusDuplicity::None;
	}
	return Data->Duplicity;
}

float UStatus::GetOriginalLifespan() const
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatus] Can't get original lifespan, data invalid!");
		return -1;
	}
	return Data->OriginalLifespan;
}

float UStatus::GetCurrentLifespan() const
{
	return CurrentLifespan;
}

EStatusGroup UStatus::GetGroup() const
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatus] Can't get group, data invalid!");
		return EStatusGroup::None;
	}
	
	return Data->Group;
}

const UStatusData* UStatus::GetData() const
{
	return Data;
}
