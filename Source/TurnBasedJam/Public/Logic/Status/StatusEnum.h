// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StatusEnum.generated.h"

/**
 * 
 */
UENUM()
enum class EStatusEnum:uint8
{
	ST_None,
	ST_Block,
	ST_Poison,
	ST_Confused
};
