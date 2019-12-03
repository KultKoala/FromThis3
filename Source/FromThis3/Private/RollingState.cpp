// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/RollingState.h"
#include "Public/CharacterStateComponent.h"

URollingState::URollingState(const FObjectInitializer & ObjectInitializer)
{
}

bool URollingState::TryEnterState(UCharacterStateComponent * StateComp)
{
	//check for identifying state

	UE_LOG(LogTemp, Warning, TEXT("Trying to Enter Rolling State"))

		switch (StateComp->GetCurrentStateEnum())
		{
		case EState::Idle:
			StateComp->UpdateCurrentState(this);
			return true;

			break;

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

void URollingState::InitState()
{
	StateStatus = EStateStatus::Starting;
	StateEnum = EState::Rolling;
}

bool URollingState::ExitState()
{
	return false;
}

void URollingState::PostInitProperties()
{
	Super::PostInitProperties();
	StateEnum = EState::Idle;
}
