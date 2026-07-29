// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Actions/ActionSolver.h"

#include "Logic/Actions/Action.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"

void UActionSolverLibrary::SolveAction(const FAction& Action)
{
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log,
		"[UActionSolverLibrary] Solving action casted by " + Action.Caster.GetName() + " on " + Action.Target.GetName() + ".");

	
}
