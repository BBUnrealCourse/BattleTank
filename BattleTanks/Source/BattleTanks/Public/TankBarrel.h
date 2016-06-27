// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesElevation = 35.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinDegreesElevation = 0.0f;
};
