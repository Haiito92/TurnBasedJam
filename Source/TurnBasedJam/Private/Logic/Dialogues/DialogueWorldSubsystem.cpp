// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic/Dialogues/DialogueWorldSubsystem.h"

#include "Logic/Debug/TurnBasedDebugLibrary.h"
#include "Logic/Dialogues/DialogueData.h"

bool UDialogueWorldSubsystem::InitDialogueSubsystem()
{
	return true;
}

void UDialogueWorldSubsystem::StartDialogue(const UDialogueData* NewDialogueData)
{
	if (!IsValid(NewDialogueData))
	{
		UTurnBasedDebugLibrary::Print(EDebugMessageType::Warning, "[UDialogueWorldSubsystem] Can't start nullptr dialogue data.");
		return;
	}
	
	if (CurrentDialogue != nullptr)
	{
		EndCurrentDialogue();
	}
	
	CurrentDialogue = NewDialogueData;
	CurrentSentenceIndex = -1;
	
	DialogueStarted.Broadcast(CurrentDialogue);
	
	PlayNextSentence();
}

void UDialogueWorldSubsystem::PlayNextSentence()
{
	if (!IsValid(CurrentDialogue)) return;
	
	CurrentSentenceIndex++;
	
	if (CurrentSentenceIndex >= CurrentDialogue->Sentences.Num())
	{
		EndCurrentDialogue();
		return;
	}
	
	NextSentencePlayed.Broadcast(CurrentDialogue->Sentences[CurrentSentenceIndex]);
}

void UDialogueWorldSubsystem::EndCurrentDialogue()
{
	if (!IsValid(CurrentDialogue)) return;
	
	DialogueEnded.Broadcast(CurrentDialogue);
	CurrentSentenceIndex = -1;
	CurrentDialogue = nullptr;
}

bool UDialogueWorldSubsystem::IsPlayingDialogue() const
{
	return CurrentDialogue != nullptr;
}
