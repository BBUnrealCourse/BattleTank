// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "public/tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;	
	virtual void Tick(float DeltaSeconds) override;

	ATank* GetAIControlledTank() const;
	ATank* GetPlayerTank() const;
};
