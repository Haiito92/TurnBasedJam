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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText StatusName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Sprite;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;
};
