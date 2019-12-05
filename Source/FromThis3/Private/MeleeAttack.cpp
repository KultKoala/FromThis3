// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/MeleeAttack.h"
#include "Public/CharacterStateComponent.h"

UMeleeAttack::UMeleeAttack(const FObjectInitializer & ObjectInitializer)
{
	SetFlags(RF_StrongRefOnFrame);
}

bool UMeleeAttack::TryEnterState(UCharacterStateComponent * StateComp)
{
	//check for identifying state

	UE_LOG(LogTemp,Warning,TEXT("Trying to Enter Attack State"))

	switch (StateComp->GetCurrentStateEnum())
	{
	case EState::Idle:
		StateComp->UpdateCurrentState(this);
		return true;

	break;

	case EState::Attacking:
		if (StateComp->GetCurrentStateStatus() >= EStateStatus::CanCancel) {
			StateComp->UpdateCurrentState(this);
			UE_LOG(LogTemp,Warning,TEXT("Entering Next Attack"))
			return true;
		}
		else {
			return false;
		}
	break;

	case EState::Rolling:
		if (StateComp->GetCurrentStateStatus() >= EStateStatus::CanCancel) {
			StateComp->UpdateCurrentState(this);
			UE_LOG(LogTemp, Warning, TEXT("Entering Next Attack"))
				return true;
		}
		else {
			return false;
		}
		break;

	default:
		return false;
		break;
	}

}

void UMeleeAttack::InitState()
{
	StateStatus = EStateStatus::Starting;
	StateEnum = EState::Attacking;
}

bool UMeleeAttack::ExitState()
{
	return false;
}

void UMeleeAttack::PostInitProperties()
{
	Super::PostInitProperties();
	StateEnum = EState::Idle;
}
