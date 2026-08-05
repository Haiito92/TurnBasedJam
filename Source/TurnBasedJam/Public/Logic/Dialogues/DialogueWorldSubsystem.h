// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DialogueWorldSubsystem.generated.h"

struct FSentence;
class UDialogueData;
/**
 * 
 */
UCLASS()
class TURNBASEDJAM_API UDialogueWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable)
	bool InitDialogueSubsystem();
	
	UFUNCTION(BlueprintCallable)
	void StartDialogue(const UDialogueData* NewDialogueData);
	
	UFUNCTION(BlueprintCallable)
	void PlayNextSentence();
	
	UFUNCTION(BlueprintCallable)
	void EndCurrentDialogue();
	
	UFUNCTION(BlueprintCallable)
	bool IsPlayingDialogue() const;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueStartedSignature, const UDialogueData*, DialogueData);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNextSentencePlayedSignature, const FSentence&, Sentence);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueEndedSignature, const UDialogueData*, DialogueData);
	
	UPROPERTY(BlueprintAssignable)
	FDialogueStartedSignature DialogueStarted;

	UPROPERTY(BlueprintAssignable)
	FNextSentencePlayedSignature NextSentencePlayed;
	
	UPROPERTY(BlueprintAssignable)
	FDialogueEndedSignature DialogueEnded;

private:
	UPROPERTY()
	TObjectPtr<const UDialogueData> CurrentDialogue;
	
	UPROPERTY()
	int CurrentSentenceIndex = -1;
};
