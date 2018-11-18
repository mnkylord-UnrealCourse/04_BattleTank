// Fill out your copyright notice in the Description page of Project Settings.

// class header ===============================================================
#include "TankAIController.h"

// UE4 includes ===============================================================
#include "Engine/World.h"

// custom includes ============================================================
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* Me = Cast<ATank>(GetPawn());
	ATank* Player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Me && Player)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s aim at (%s)"), *Me->GetName(), *Player->GetActorLocation().ToString());
		Me->AimAt(Player->GetActorLocation());
		Me->Fire();
	}
}