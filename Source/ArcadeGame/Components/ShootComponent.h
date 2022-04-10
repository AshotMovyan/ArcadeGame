// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "..//Actors/Projectiles/ShootProjectile.h"

#include "ShootComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ARCADEGAME_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UShootComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Shoot();

	FTimerHandle ShootingTimer;

public:
	UFUNCTION(BlueprintCallable, Category = "Shooting")
		void StartShooting();

	UFUNCTION(BlueprintCallable, Category = "Shooting")
		void StopShooting();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controls")
		float DeltaShootTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controls")
		TSubclassOf<AShootProjectile> ProjectileClass;

};