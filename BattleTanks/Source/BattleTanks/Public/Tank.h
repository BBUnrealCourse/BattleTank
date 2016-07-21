// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Projectile)
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.0f;	// Find sensible starting value (trying 1000 m/s)
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.0f;

	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};
