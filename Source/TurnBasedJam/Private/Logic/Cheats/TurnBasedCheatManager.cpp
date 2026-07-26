// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/Cheats/TurnBasedCheatManager.h"
#include "TurnBasedJam/Public/Logic/Debug/TurnBasedDebugLibrary.h"

void UTurnBasedCheatManager::ToggleDebug(bool DebugOn)
{
	// GEngine->AddOnScreenDebugMessage(
	// 	-1, 
	// 	3.0f,
	// 	FColor::Green,
	// 	"Debug" + LexToString(DebugOn));
	
	UTurnBasedDebugLibrary::ToggleDebug(DebugOn);
}
