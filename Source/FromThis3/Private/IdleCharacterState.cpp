// Fill out your copyright notice in the Description page of Project Settingss.
#include "..\Public\IdleCharacterState.h"
#include "Public\CharacterStateComponent.h"

UIdleCharacterState::UIdleCharacterState(const FObjectInitializer & ObjectInitializer)
{
}

bool UIdleCharacterState::TryEnterState(UCharacterStateComponent * StateComp)
{
	//check for identifying state

	switch (StateComp->GetCurrentStateEnum())
	{
	case EState::Attacking:
		if (StateComp->GetCurrentStateStatus() >= EStateStatus::CanCancel) {
			StateComp->UpdateCurrentState(this);
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

void UIdleCharacterState::InitState()
{
	StateStatus = EStateStatus::Starting;
	StateEnum = EState::Idle;
}

bool UIdleCharacterState::ExitState()
{
	return false;
}

void UIdleCharacterState::PostInitProperties()
{
	Super::PostInitProperties();
	StateEnum = EState::Idle;
}
