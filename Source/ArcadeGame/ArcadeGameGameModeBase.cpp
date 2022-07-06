// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArcadeGameGameModeBase.h"

AArcadeGameGameModeBase::AArcadeGameGameModeBase()
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
}
