// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterState.h"
#include "CharacterStateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FROMTHIS3_API UCharacterStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Map of All Character States Available
	UPROPERTY()
	TMap<EState, UCharacterState*> CharacterStateMap;

	//find state in set and try it
	bool TryState(EState);

private:
	//Current State Activate
	UPROPERTY()
	UCharacterState *CurrentState;

	//Previous State
	UPROPERTY()
	UCharacterState *PreviousState;

	//State to be executed when window is available
	UPROPERTY()
	UCharacterState *QueuedState;

public:
	UFUNCTION(BlueprintCallable)
	EState GetCurrentStateEnum();

	UFUNCTION(BlueprintCallable)
	EStateStatus GetCurrentStateStatus() { return CurrentState->StateStatus; };

	UFUNCTION(BlueprintCallable)
	void SetCurrentStateStatus(EStateStatus NewStateStatus) { CurrentState->StateStatus = NewStateStatus; };

	/*Update Current State to New State and */
	void UpdateCurrentState(UCharacterState * NewState);


		
};
