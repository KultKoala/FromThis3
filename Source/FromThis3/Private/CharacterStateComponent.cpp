// Fill out your copyright notice in the Description page of Project Settings.


#include "public/CharacterStateComponent.h"
#include "public/IdleCharacterState.h"
#include "public/MeleeAttack.h"

// Sets default values for this component's properties
UCharacterStateComponent::UCharacterStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Initialize All States
	UIdleCharacterState *IdleState = CreateDefaultSubobject<UIdleCharacterState>(TEXT("Idle"));
	UMeleeAttack * MeleeAttackState = CreateDefaultSubobject<UMeleeAttack>(TEXT("Melee"));

	CharacterStateMap.Add(EState::Idle, IdleState);
	CharacterStateMap.Add(EState::Attacking, MeleeAttackState);
	CurrentState = IdleState;

}


// Called when the game starts
void UCharacterStateComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UCharacterStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCharacterStateComponent::TryState(EState ETryState)
{

	if (IsValid(*CharacterStateMap.Find(ETryState))) {
		return (*CharacterStateMap.Find(ETryState))->TryEnterState(this);
	}
	else {
		UE_LOG(LogTemp,Error, TEXT("Retrieving Invalid Map Data"))
	}

	return false;
}

EState UCharacterStateComponent::GetCurrentStateEnum()
{
	return CurrentState->GetStateEnum();
}

void UCharacterStateComponent::UpdateCurrentState(UCharacterState * NewState)
{
	PreviousState = CurrentState;
	CurrentState = NewState;
	CurrentState->InitState();
}

