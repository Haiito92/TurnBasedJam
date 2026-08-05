// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Speaker.h"
#include "UObject/Object.h"
#include "Sentence.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSentence
{
	GENERATED_BODY()
	
public:
	FSentence() = default;
	~FSentence() = default;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ESpeaker Speaker = ESpeaker::None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Sentence;
};

