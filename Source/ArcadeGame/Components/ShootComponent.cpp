// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UShootComponent::UShootComponent()
	:
	DeltaShootTime(1.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
		
}


// Called when the game starts
void UShootComponent::BeginPlay()
{
	Super::BeginPlay();

	StartShooting();
	
}

void UShootComponent::Shoot()
{
		
	for (FShootInfo ShootInfo : ShootInfos)
	{
		FActorSpawnParameters SpawnParametrs;
		SpawnParametrs.Owner = GetOwner();

		FVector SpawnLocation =
			GetOwner()->GetActorLocation()
			+ 
			GetOwner()->GetActorRotation().RotateVector(ShootInfo.Offset);

		FRotator SpawnRotation = GetOwner()->GetActorRotation();
		SpawnRotation.Add(0.f, ShootInfo.Angle, 0.f);

		GetWorld()->SpawnActor<AShootProjectile>(ShootInfo.ProjectileClass, SpawnLocation, SpawnRotation, SpawnParametrs);

	}
}

void UShootComponent::StartShooting()
{
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent::Shoot, DeltaShootTime, true, DeltaShootTime);
}	

void UShootComponent::StopShooting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}

