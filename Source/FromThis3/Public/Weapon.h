// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class FROMTHIS3_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	USkeletalMeshComponent * WeaponSkeletalMeshComp;

	UPROPERTY(EditInstanceOnly, Category = "Weapon")
	TArray<AActor*> DamagedEnemies;

	UPROPERTY()
	FTimerHandle DamageTickerTimer;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StartDealingDamage();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void DealDamageToOverlappingEnemies();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StopDealingDamage();

private:


};
