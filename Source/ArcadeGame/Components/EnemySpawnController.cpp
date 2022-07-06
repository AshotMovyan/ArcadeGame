// Fill out your copyright notice in the Description page of Project Settings.


#include "../Components/EnemySpawnController.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	//SpawnStage = FEnemySpawntInfo();
	//SpawnStage.NumOfEnemies = 10;
	//SpawnStage.SpawnDelay = 1.f;
	


	StartSpawnStage();	
}

void UEnemySpawnController::SpawnEnemy()
{
	FActorSpawnParameters SpawnParametrs;
	GetWorld()->SpawnActor<AEnemyPawn>(SpawnStage.EnemyClass, SpawnStage.SpawnTransform, SpawnParametrs);
		
	if (++EnemiesSpawned < SpawnStage.NumOfEnemies)
	{
		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, false);
	}
}

void UEnemySpawnController::StartSpawnStage()
{
	FRandomStream Random;
	Random.GenerateNewSeed();
	EnemiesSpawned = 0;
	SpawnStage = SpawnStages[Random.RandRange(0, SpawnStages.Num() - 1)];

	SpawnEnemy();

	GetWorld()->GetTimerManager().SetTimer(ChangeSpawnTimer, this, &UEnemySpawnController::StartSpawnStage,
		Random.RandRange(StageMinDelay, StageMaxnDelay), false);

}
