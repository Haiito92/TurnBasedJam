// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Status/Status.h"

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
	CurrentLifespan = OriginalLifespan;
}

void UStatus::ResetStatus()
{
	CurrentLifespan = OriginalLifespan;
}

const EStatusEnum& UStatus::GetEnum() const
{
	return Enum;
}

const EStatusDuplicity& UStatus::GetDuplicity() const
{
	return Duplicity;
}

float UStatus::GetOriginalLifespan() const
{
	return OriginalLifespan;
}

float UStatus::GetCurrentLifespan() const
{
	return CurrentLifespan;
}

const EStatusGroup& UStatus::GetGroup() const
{
	return Group;
}

const UStatusData* UStatus::GetData() const
{
	return Data;
}
