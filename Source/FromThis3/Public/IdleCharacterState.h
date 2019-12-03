// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "IdleCharacterState.generated.h"

/**
 * 
 */
UCLASS()
class FROMTHIS3_API UIdleCharacterState : public UCharacterState
{
	GENERATED_BODY()

	UIdleCharacterState(const FObjectInitializer& ObjectInitializer);

	bool TryEnterState(UCharacterStateComponent* StateComp) override;
	
	void InitState() override;

	bool ExitState() override;

	void PostInitProperties() override;

	
};
