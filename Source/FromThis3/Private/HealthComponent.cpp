// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Net/UnrealNetwork.h"
#include "Public/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Health = 100;
	MaxHealth = 200;
	SetIsReplicated(true);

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor *Owner = GetOwner();

	if (Owner)
	{
		if (GetOwnerRole() == ROLE_Authority) {
			Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage);
		}

	}

}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::HandleDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (!bIsDead) {
		Health -= Damage;
		Health = FMath::Clamp(Health, 0.0f, MaxHealth);
		DamageDelegate.Broadcast(Damage, DamageCauser, DamageType);
		if (Health <= 0.0f) {
			DeathDelegate.Broadcast();
			bIsDead = true;
		}
	}
}

void UHealthComponent::Heal(float HealAmount)
{
	if (!bIsDead) {
		Health += HealAmount;
		HealDelegate.Broadcast(HealAmount);
		Health = FMath::Clamp(Health, 0.0f, MaxHealth);
	}
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{

	DOREPLIFETIME(UHealthComponent, Health);
}

