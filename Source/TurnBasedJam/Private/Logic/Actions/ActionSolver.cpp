// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Actions/ActionSolver.h"

#include "Logic/Actions/ActionContext.h"
#include "Logic/Actions/Action.h"
#include "Logic/Debug/TurnBasedDebugLibrary.h"

void UActionSolverLibrary::SolveAction(const FActionContext& ActionContext)
{
	UTurnBasedDebugLibrary::Print(EDebugMessageType::Log,
		"[UActionSolverLibrary] Solving action casted by " + ActionContext.Caster.GetName() + " on " + ActionContext.Target.GetName() + ".");

	ActionContext.Action->ApplyActionStrategy(ActionContext.Target, ActionContext.Caster);
}
