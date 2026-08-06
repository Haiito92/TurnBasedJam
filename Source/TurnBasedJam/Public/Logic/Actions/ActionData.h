// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ActionData.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EActionType: uint8
{
	None,
	Pass,
	Block,
	Bite,
	PoisonStrike,
	SeethingPoison,
	Claws,
	PsychicHorrorEvocation,
	MentalClaws
	
};

UCLASS()
class TURNBASEDJAM_API UActionData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EActionType Type = EActionType::None;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText ActionName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Sprite;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;
};
