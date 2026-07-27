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
				FinalMessage = Message;
				UE_LOGFMT(LogTemp, Log, "{0}", FinalMessage);
				break;
			}
		case EDebugMessageType::Warning:
			{
				FinalMessage = "[Warning] " + Message;
				FinalColor = FColor::Yellow;
				UE_LOGFMT(LogTemp, Warning, "{0}", FinalMessage);
				break;
			}
		case EDebugMessageType::Error:
			{
				FinalMessage += "[Error] " + Message;
				FinalColor = FColor::Red;
				UE_LOGFMT(LogTemp, Error, "{0}", FinalMessage);
				break;
			}
	}
	
	GEngine->AddOnScreenDebugMessage(
		-1,
		TimeToDisplay,
		FinalColor,
		FinalMessage);
}

bool UTurnBasedDebugLibrary::DebugOn = true;
