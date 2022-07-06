	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "..//Pawns/EnemyPawn.h"
#include "EnemySpawnController.generated.h"

USTRUCT(BlueprintType)
struct FEnemySpawntInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
		TSubclassOf<AEnemyPawn> EnemyClass = AEnemyPawn::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
		FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "E	nemies")
		int NumOfEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
		float SpawnDelay;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEGAME_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SpawnEnemy();

	void StartSpawnStage();
	
	FEnemySpawntInfo SpawnStage;

	int EnemiesSpawned;

	FTimerHandle ChangeSpawnTimer;
	FTimerHandle EnemySpawnTimer;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		TArray<FEnemySpawntInfo> SpawnStages;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		float StageMinDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		float StageMaxnDelay;


};






