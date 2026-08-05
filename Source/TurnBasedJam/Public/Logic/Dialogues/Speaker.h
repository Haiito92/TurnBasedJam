// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Speaker.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ESpeaker : uint8
{
	None,
	Hero,
	Vampire
};
