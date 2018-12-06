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


void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

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

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, FiringSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

