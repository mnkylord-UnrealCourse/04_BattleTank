// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController failed to possess tank!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing [%s] @ (%s)"), *ControlledTank->GetName(), *ControlledTank->GetActorLocation().ToString());
	}
}


