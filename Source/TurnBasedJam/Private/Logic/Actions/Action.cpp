// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Actions/Action.h"
#include "Logic/Actions/ActionData.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"

bool UAction::ApplyActionStrategy_Implementation(ATurnBasedActor* ActionTarget)
{
	if (!IsValid(Data))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UAction] Can't apply strategy, data invalid!");
		return false;
	}
	
	return true;
}

UActionData* UAction::GetActionData() const
{
	return Data;
}

const TArray<TSubclassOf<UStatus>>& UAction::GetStatusClassesToApply() const
{
	return StatusClassesToApply;
}
