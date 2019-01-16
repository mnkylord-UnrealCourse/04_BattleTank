// Fill out your copyright notice in the Description page of Project Settings.

// class header ===============================================================
#include "Tank.h"

// UE4 includes ===============================================================
#include "Engine/World.h"

// custom includes ============================================================
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"


bool ATank::Fire()
{
	if (!Barrel || (FPlatformTime::Seconds() - LastFireTime) < ReloadTime) { return false; }
	LastFireTime = FPlatformTime::Seconds();
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
		Projectile_BP,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
	);
	if (!Projectile) { UE_LOG(LogTemp, Warning, TEXT("No Projectile")); return false; }
	Projectile->Launch(FiringSpeed);
	return true;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("[TANK] constructor"));

	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent)
	{
		//UE_LOG(LogTemp, Warning, TEXT("No TankAimingComponent!!"));
		return;
	}
	TankAimingComponent->AimAt(HitLocation, FiringSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	//TankAimingComponent = *Cast<TankAimingComponent>(GetComponentByClass(TankAimingComponent));
	//TankAimingComponent = FindComponentByClass(const TankAimingComponent);
}
