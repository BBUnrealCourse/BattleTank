// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	// How close can the tank get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float AcceptanceRadius = 8000.0f;

private:
	virtual void BeginPlay() override;	
	virtual void Tick(float DeltaSeconds) override;
};
