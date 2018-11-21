// Fill out your copyright notice in the Description page of Project Settings.

// class header ===============================================================
#include "TankTrack.h"

// UE4 includes ===============================================================
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//if (Throttle) { UE_LOG(LogTemp, Warning, TEXT("%s throttle at %f"), *GetName(), Throttle); }
	FVector ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}