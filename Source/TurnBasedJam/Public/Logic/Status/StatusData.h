// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StatusData.generated.h"

/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UStatusData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Status|Info")
	FText StatusName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Status|Info")
	UTexture2D* Sprite;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Status|Info")
	FText Description;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Status|Data")
	float OriginalLifespan;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status|Data")
	EStatusEnum Enum = EStatusEnum::ST_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status|Data")
	EStatusDuplicity Duplicity = EStatusDuplicity::Solo;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status|Data")
	EStatusGroup Group = EStatusGroup::GlobalStartTurn;
};
