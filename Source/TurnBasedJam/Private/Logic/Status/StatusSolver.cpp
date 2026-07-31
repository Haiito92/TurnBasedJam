// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Status/StatusSolver.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/Status/StatusComponent.h"
#include "Logic/TurnMechanic/TurnBasedActor.h"

void UStatusSolver::ApplyStatus(const FApplyStatusContext& StatusContext)
{
	UStatusComponent* StatusComponent = StatusContext.Target->GetStatusComponent();
	
	if (!IsValid(StatusComponent))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatusSolver] Couldn't apply status, status component invalid!");
		return;
	}

	if (!IsValid(StatusContext.StatusClass->GetClass()))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatusSolver] Couldn't apply status, status class invalid!");
		return;
	}
	
	UStatus* AppliedStatus = nullptr;
	if (!StatusComponent->ApplyStatus(StatusContext.StatusClass, AppliedStatus) || !IsValid(AppliedStatus)) return;
	
	AppliedStatus->ApplyStatus(StatusContext.Target);
}

void UStatusSolver::TickStatus(const FTickMultipleStatusContext& Context)
{
	UStatusComponent* StatusComponent = Context.Holder->GetStatusComponent();
	
	if (!IsValid(StatusComponent))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatusSolver] Couldn't remove status, status component invalid!");
		return;
	}
	
	TArray<UStatus*> StatusToTick = StatusComponent->GetAppliedStatusByGroup(Context.Group);
	
	for (UStatus* Status : StatusToTick)
	{
		Status->TickStatus(Context.Holder);
	}
}

void UStatusSolver::RemoveStatus(const FRemoveStatusContext& Context)
{
	UStatusComponent* StatusComponent = Context.Holder->GetStatusComponent();
	
	if (!IsValid(StatusComponent))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatusSolver] Couldn't remove status, status component invalid!");
		return;
	}
	
	if (!StatusComponent->RemoveStatus(Context.Status)) return;
	
	Context.Status->RemoveStatus(Context.Holder);
}

void UStatusSolver::PurgeStatus(const FPurgeStatusContext& Context)
{
	UStatusComponent* StatusComponent = Context.Holder->GetStatusComponent();
	
	if (!IsValid(StatusComponent))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Error, "[UStatusSolver] Couldn't purge status, status component invalid!");
		return;
	}
	
	TArray<UStatus*> StatusToPurge = StatusComponent->GetAppliedStatusByGroup(Context.Group);
	
	for (UStatus* Status : StatusToPurge)
	{
		if (Status->Lifespan > 0) continue;
		
		RemoveStatus({Status, Context.Holder});
	}
}
