// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/Debug/TurnBasedDebugLibrary.h"


void UTurnBasedDebugLibrary::ToggleDebug(bool InDebugOn)
{
	DebugOn = InDebugOn;
}

void UTurnBasedDebugLibrary::Print(const EDebugMessageType& MessageType, const FString& Message, float TimeToDisplay)
{
	if (!DebugOn) return;
	
	FString FinalMessage;
	FColor FinalColor = FColor::White;

	switch (MessageType)
	{
		case EDebugMessageType::Log:
			{
				break;
			}
		case EDebugMessageType::Warning:
			{
				FinalMessage += "[Warning] ";
				FinalColor = FColor::Yellow;
				break;
			}
		case EDebugMessageType::Error:
			{
				FinalMessage += "[Error] ";
				FinalColor = FColor::Red;
				break;
			}
	}
	
	FinalMessage += Message;
	
	GEngine->AddOnScreenDebugMessage(
		-1,
		TimeToDisplay,
		FinalColor,
		FinalMessage);
}

bool UTurnBasedDebugLibrary::DebugOn = false;
