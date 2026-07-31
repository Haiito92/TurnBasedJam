// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Status/Status.h"

void UStatus::ApplyStatus_Implementation(ATurnBasedActor* Target)
{
}

void UStatus::TickStatus_Implementation(ATurnBasedActor* Target)
{
	Lifespan--;
}

void UStatus::RemoveStatus_Implementation(ATurnBasedActor* Target)
{
}
