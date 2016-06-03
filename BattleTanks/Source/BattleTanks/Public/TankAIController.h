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
	ATank* GetAIControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;	
	
};