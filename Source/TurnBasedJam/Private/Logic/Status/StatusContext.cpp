// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Status/StatusContext.h"

FApplyStatusContext::FApplyStatusContext(const TSubclassOf<UStatus>& InStatusClass, ATurnBasedActor* InTarget):
StatusClass(InStatusClass),
Target(InTarget)
{
}

FTickMultipleStatusContext::FTickMultipleStatusContext(const EStatusGroup& InGroup, ATurnBasedActor* InHolder):
Group(InGroup),
Holder(InHolder)
{
	
}

FRemoveStatusContext::FRemoveStatusContext(UStatus* InStatus, ATurnBasedActor* InHolder):
Status(InStatus),
Holder(InHolder)
{
}

FPurgeStatusContext::FPurgeStatusContext(const EStatusGroup& InGroup, ATurnBasedActor* InHolder):
Group(InGroup),
Holder(InHolder)
{
}
