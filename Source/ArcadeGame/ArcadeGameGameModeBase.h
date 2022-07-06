// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Components/EnemySpawnController.h"

#include "ArcadeGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARCADEGAME_API AArcadeGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AArcadeGameGameModeBase();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemies", meta = (AllowPrivateAccess = "true"))
		UEnemySpawnController* EnemySpawnController;
};
	