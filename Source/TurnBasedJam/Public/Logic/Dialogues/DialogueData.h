// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Logic/Dialogues/Sentence.h"
#include "DialogueData.generated.h"


/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UDialogueData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FSentence> Sentences;
};
