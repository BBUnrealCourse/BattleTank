// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has been possessed"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		// TODO Tell controlled tank to aim at this point
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location if linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if(GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction, and see what we hit (up to a max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded but must be passed in	
	ATankPlayerController::DeprojectScreenPositionToWorld(
				ScreenLocation.X, 
				ScreenLocation.Y, 
				CameraWorldLocation, 
				LookDirection
		);
	return true;
}