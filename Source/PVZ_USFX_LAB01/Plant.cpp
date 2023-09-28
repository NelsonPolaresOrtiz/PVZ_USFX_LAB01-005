// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "Components/StaticMeshComponent.h"
#include "PVZ_USFX_LAB01GameMode.h"
#include "Zombie.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlantMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plant Mesh"));
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	if (PlantMesh.Succeeded())
	{
		PlantMeshComponent->SetStaticMesh(PlantMesh.Object);
	}
	RootComponent = PlantMeshComponent;

	//PlantMesh->AttachTo(Root);
	energia = 0.1;
}


void APlant::eliminarZombie(APVZ_USFX_LAB01GameMode* GameModeBasePVZ)
{

	AZombie* ZombieActual;
	ZombieActual = GameModeBasePVZ->vectorZombies.Pop(0);
	ZombieActual->energia -= 10.0f;
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

