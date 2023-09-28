// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB01GameMode.generated.h"

class AZombie;
class APlant;
UCLASS(MinimalAPI)
class APVZ_USFX_LAB01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APVZ_USFX_LAB01GameMode();

	// Declarar un vector de objetos
	TArray<AZombie*> VectorZombies;

	// Array para Plantas
	TArray<APlant*> VectorPlants;
	FTimerHandle Temporizador;
	//Tmap
	TMap<FString, APlant*> MapPlantas;
	AZombie* NuevoZombie;
	void aumentovelocidad();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//AZombie* NuevoZombie;
	//void aumentovelocidad();
};



