// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AZombie::AZombie()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ZombieMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));
	RootComponent = ZombieMesh;

	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ZombieMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}

	energia = 100.0f;
	velocidad = 0.2f;
}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Supongamos que ya tienes una instancia de APlantaActor llamada MyPlantaActor
	FVector LocalizaionObjetivo = FVector(-800.0f, -600.0f, 160.0f);
	FVector Direccion = LocalizaionObjetivo - FVector(-800.0f, 400.0f, 160.0f);
	FVector TargetLocation = FVector(100.0f, 0.0f, 0.0f); // Cambia la ubicación objetivo según tus necesidades
	float MovementSpeed = 100.0f; // Velocidad de movimiento

	// Calcula la dirección y distancia al objetivo
	FVector Direction = (TargetLocation - this->GetActorLocation()).GetSafeNormal();
	float DistanceToTarget = FVector::Dist(TargetLocation, this->GetActorLocation());

	// Calcula el desplazamiento en este frame
	float DeltaMove = MovementSpeed * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanceToTarget)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(TargetLocation);
	}
	else
	{
		// Mueve el objeto en la dirección calculada
		this->AddActorWorldOffset(Direction * DeltaMove);
	}




}

