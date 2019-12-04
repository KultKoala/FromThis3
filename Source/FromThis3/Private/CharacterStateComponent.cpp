// Fill out your copyright notice in the Description page of Project Settings.


#include "public/CharacterStateComponent.h"
#include "public/IdleCharacterState.h"
#include "public/RollingState.h"
#include "public/MeleeAttack.h"

// Sets default values for this component's properties
UCharacterStateComponent::UCharacterStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UCharacterStateComponent::BeginPlay()
{
	Super::BeginPlay();

	//Initialize All States
	UIdleCharacterState *IdleState = NewObject<UIdleCharacterState>();
	UMeleeAttack * MeleeAttackState = NewObject<UMeleeAttack>();
	URollingState * RollState = NewObject<URollingState>();

	CurrentState = IdleState;

	CharacterStateArray.Add(IdleState);
	CharacterStateArray.Add(MeleeAttackState);
	CharacterStateArray.Add(RollState);


	CharacterStateMap.Add(EState::Idle, IdleState);
	CharacterStateMap.Add(EState::Attacking, MeleeAttackState);
	CharacterStateMap.Add(EState::Rolling, RollState);


	IdleState->SetFlags(RF_StrongRefOnFrame);
	MeleeAttackState->SetFlags(RF_StrongRefOnFrame);
	RollState->SetFlags(RF_StrongRefOnFrame);


}


// Called every frame
void UCharacterStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//for (auto item : CharacterStateMap) {

	//	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);

	//	UE_LOG(LogTemp, Warning, TEXT("%s"), *(EnumPtr->GetValueAsString(item.Key)))
	//}

	
	// ...
}

bool UCharacterStateComponent::TryState(EState ETryState)
{
	UCharacterState * NewState = CharacterStateMap[ETryState];
	if (NewState != NULL) {
		return (NewState->TryEnterState(this));
	}
	else {
		UE_LOG(LogTemp,Error, TEXT("Retrieving NULL map data"))
	}

	return false;
}

EState UCharacterStateComponent::GetCurrentStateEnum()
{
	if (CurrentState) {
		return CurrentState->GetStateEnum();
	}
	else {
		UE_LOG(LogTemp,Error,TEXT("No state found"))
		return EState::Idle;
	}
	
}

void UCharacterStateComponent::UpdateCurrentState(UCharacterState * NewState)
{
	PreviousState = CurrentState;
	CurrentState = NewState;
	CurrentState->InitState();
}

