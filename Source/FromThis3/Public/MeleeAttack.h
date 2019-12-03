// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class FROMTHIS3_API UMeleeAttack : public UCharacterState
{
	GENERATED_BODY()

	UMeleeAttack(const FObjectInitializer& ObjectInitializer);

	bool TryEnterState(UCharacterStateComponent* StateComp) override;

	void InitState() override;

	bool ExitState() override;

	void PostInitProperties() override;
	
};
