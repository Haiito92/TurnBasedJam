// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/FightActors/Vampire.h"

#include "Kismet/KismetMathLibrary.h"
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
	
	SetNextActionData(nullptr);
	
	SetNextActionCaster(this);
	SetNextActionTarget(Enemy);


	if (ActionsData.Num() > 0)
	{
		int index = UKismetMathLibrary::RandomInteger(ActionsData.Num());
		
		UActionData* ActionData = ActionsData[index];
		
		if (ActionData == LastActionData)
		{
			index = (index + 1) % ActionsData.Num();
			ActionData = ActionsData[index];
		}
		
		LastActionData = ActionData;
		
		SetNextActionData(ActionData);
		
		FString Message = "[AVampire] Vampire chose: " + ActionData->ActionName.ToString();
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Log, Message);
	}
	else
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[AVampire] Can't chose action, ActionsData.Num() == 0!");
	}
	
	ValidateNextAction();
}

