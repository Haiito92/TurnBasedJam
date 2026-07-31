// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/FightActors/Vampire.h"

#include "Kismet/KismetMathLibrary.h"
#include "Logic/Actions/Action.h"
#include "Logic/Actions/ActionData.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"


// Sets default values
AVampire::AVampire()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AVampire::PrepareTurn(ATurnBasedActor* Enemy)
{
	TurnPreparationStarted.Broadcast();
	
	SetNextAction(nullptr);
	
	SetNextActionCaster(this);
	SetNextActionTarget(Enemy);


	if (Actions.Num() > 0)
	{
		int index = UKismetMathLibrary::RandomInteger(Actions.Num());
		
		UAction* Action = Actions[index];
		
		if (Action == LastAction && Actions.Num() > 1)
		{
			index = (index + 1) % Actions.Num();
			Action = Actions[index];
		}
		
		LastAction = Action;
		
		SetNextAction(Action);
		
		if (IsValid(Action->GetActionData()))
		{
			FString Message = "[AVampire] Vampire chose: " + Action->GetActionData()->ActionName.ToString();
			UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, Message);
		}
		else
		{
			UTurnBasedDebugLibrary::Print(EDebugMessageType::Warning, "[AVampire] Can't log action chosen name because data is nullptr ");
		}
		
	}
	else
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[AVampire] Can't chose action, ActionsData.Num() == 0!");
	}
	
	ValidateNextAction();
}

