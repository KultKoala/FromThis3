// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterState.generated.h"

class UCharacterStateComponent;

/**
 * 
 */

UENUM(BlueprintType)
enum class EState : uint8
{
	Idle	 	UMETA(DisplayName = "Idle"),
	Attacking 	UMETA(DisplayName = "Attacking"),
	Rolling 	UMETA(DisplayName = "Rolling"),
	Defending 	UMETA(DisplayName = "Defending"),
	Walking 	UMETA(DisplayName = "Walking"),
	Running 	UMETA(DisplayName = "Running"),
};


UENUM(BlueprintType)
enum class EStateStatus : uint8
{
	InActive 	UMETA(DisplayName = "InActive"),
	Starting 	UMETA(DisplayName = "Starting"),
	InProgress 	UMETA(DisplayName = "InProgress"),
	CanQueue	UMETA(DisplayName = "CanQueue"),
	CanCancel	UMETA(DisplayName = "CanCancel"),
	Ending		UMETA(DisplayName = "Ending"),
};


UCLASS(abstract)
class FROMTHIS3_API UCharacterState : public UObject
{
	GENERATED_BODY()

public:

	//externally modifiable enum that deter
	UPROPERTY(EditAnywhere, Category = "CharacterState")
	EStateStatus StateStatus;

	//return false if cannot enter state. otherwise state is updated and true is returned
	virtual bool TryEnterState(UCharacterStateComponent* StateComp) PURE_VIRTUAL(UCharacterState::TryEnterState, return false;);

	EState GetStateEnum() { return StateEnum; }

	//reset all variables on state updated
	virtual void InitState() PURE_VIRTUAL(UCharacterState::InitStatex, ;);
	
private:	
	virtual bool ExitState() PURE_VIRTUAL(UCharacter::ExitState, return false;);

protected:
	//identifying variable for state
	UPROPERTY()
	EState StateEnum;
	
};
