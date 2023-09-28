// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plant.generated.h"

class UStaticMeshComponent;

UCLASS()
class PVZ_USFX_LAB01_API APlant : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlant();

	//class UStaticMeshComponent* PlantMesh;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PlantMeshComponent;

	void eliminarZombie(class APVZ_USFX_LAB01GameMode* GameModeBasePVZ);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float energia;
};
