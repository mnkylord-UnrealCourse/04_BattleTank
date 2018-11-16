// Fill out your copyright notice in the Description page of Project Settings.

// class header
#include "TankAimingComponent.h"

// UE4 includes ===============================================================
#include "Kismet/GameplayStatics.h"

// custom includes ============================================================
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float FiringSpeed)
{
	if (!Barrel || !Turret) { return; }

	FVector OutFiringVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool success = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutFiringVelocity,
		StartLocation,
		HitLocation,
		FiringSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (success)
	{
		FVector AimDirection = OutFiringVelocity.GetSafeNormal();
		MoveBarrelToward(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming toward (%s) at %f cm/s"), *GetOwner()->GetName(), *AimDirection.ToString(), FiringSpeed);
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("%s aim failed!!"), *GetOwner()->GetName());
	}
}

void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);

	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	DeltaRotator = AimRotator - TurretRotator;
	//UE_LOG(LogTemp, Warning, TEXT("%s Yaw = %f"), *GetOwner()->GetName(), DeltaRotator.Yaw);
	Turret->Rotate(DeltaRotator.Yaw);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}
