// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/TurnMechanic/TurnManager.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"

void UTurnManager::StartFight()
{
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, "[UTurnManager] Start Fight!");
}
