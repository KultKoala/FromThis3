// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "..\Public\Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponSkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	WeaponSkeletalMeshComp->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::StartDealingDamage()
{
	GetWorldTimerManager().SetTimer(DamageTickerTimer, this, &AWeapon::DealDamageToOverlappingEnemies, .01f, true);
}

void AWeapon::DealDamageToOverlappingEnemies()
{
	//trace from handle of the weapon out
	
	

	//find and damage enemies that haven't already been damaged

	//add newly damaged enemies to damaged enemies list
}

void AWeapon::StopDealingDamage()
{
	DamageTickerTimer.Invalidate();
	DamagedEnemies.Empty();
}

