// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/GameEvents/UIEventsHolder.h"

void UUIEventsHolder::LaunchEvent(const UIEventsType& UIEventType)
{
	switch (UIEventType)
	{
	case UIEventsType::None:
		{
			return;
		}
	case UIEventsType::PlayClicked:
		{
			PlayClicked.Broadcast();
			return;			
		}
	case UIEventsType::QuitClicked:
		{
			QuitClicked.Broadcast();
			return;
		}
	default:
		{
			return;
		}
	}
}
