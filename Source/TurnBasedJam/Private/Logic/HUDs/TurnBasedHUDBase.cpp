// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/HUDs/TurnBasedHUDBase.h"

#include "Logic/GameEvents/UIEventsHolder.h"

void ATurnBasedHUDBase::InitializeHUD(UUIEventsHolder* InUIEventsHolder)
{
	InternalInitialization(InUIEventsHolder);
	ReceiveInternalInitialization(InUIEventsHolder);
	
	SpawnWidgets();
	ReceiveSpawnWidgets();
	
	InitializeWidgets();
	ReceiveInitializeWidgets();
}

void ATurnBasedHUDBase::StartHUD()
{
	InternalStart();
	ReceiveInternalStart();
	
	StartWidgets();
	ReceiveStartWidgets();
}

void ATurnBasedHUDBase::EndHUD(bool Won)
{
	ReceiveEndHUD(Won);
}

void ATurnBasedHUDBase::InternalInitialization(UUIEventsHolder* InUIEventsHolder)
{
	UIEventHolder = InUIEventsHolder;
}

void ATurnBasedHUDBase::SpawnWidgets()
{
	
}

void ATurnBasedHUDBase::InitializeWidgets()
{
}

void ATurnBasedHUDBase::InternalStart()
{
}

void ATurnBasedHUDBase::StartWidgets()
{
}
