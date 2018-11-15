// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


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
	if (!Barrel) { return;  }

	FVector OutFiringVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool success = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutFiringVelocity,
		StartLocation,
		HitLocation,
		FiringSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (success)
	{
		FVector AimDirection = OutFiringVelocity.GetSafeNormal();
		MoveBarrelToward(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming toward (%s) at %f cm/s"), *GetOwner()->GetName(), *AimDirection.ToString(), FiringSpeed);
	}
}

void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("%s rotate barrel (%s)"), *GetOwner()->GetName(), *DeltaRotator.ToString());
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

