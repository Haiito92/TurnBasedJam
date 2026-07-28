// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnBasedJam/Public/Logic/HUDs/TurnBasedHUDBase.h"

void ATurnBasedHUDBase::InitializeHUD()
{
	InternalInitialization();
	ReceiveInternalInitialization();
	
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

void ATurnBasedHUDBase::InternalInitialization()
{
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
