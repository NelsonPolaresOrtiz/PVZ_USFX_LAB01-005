// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zombie.generated.h"

class UStaticMeshComponent;

UCLASS()
class PVZ_USFX_LAB01_API AZombie : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZombie();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ZombieMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		float energia;
	UPROPERTY(EditAnywhere)
		float velocidad;
};
