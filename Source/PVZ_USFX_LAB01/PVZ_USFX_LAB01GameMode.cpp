// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB01GameMode.h"
#include "PVZ_USFX_LAB01Pawn.h"
#include "Zombie.h"
#include "Plant.h"
#include "Math/UnrealMathUtility.h"

APVZ_USFX_LAB01GameMode::APVZ_USFX_LAB01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = APVZ_USFX_LAB01Pawn::StaticClass();
}

void APVZ_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Lugar donde quieras crear la instancia del objeto de planta
	//FVector SpawnLocation1 = FVector(-850.0f, 400.0f, 160.0f); // Cambia las coordenadas según tus necesidades

	//AZombie* NewZombieActor1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation1, FRotator::ZeroRotator);

	//FVector SpawnLocation2 = FVector(-500.0f, 200.0f, 160.0f); // Cambia las coordenadas según tus necesidades

	//AZombie* NewZombieActor2 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation2, FRotator::ZeroRotator);
	//

	//// Lugar donde quieras crear la instancia del objeto
	//FVector MinSpawnLocation = FVector(-1000.0f, -1000.0f, 0.0f);
	//FVector MaxSpawnLocation = FVector(1000.0f, 1000.0f, 0.0f);

	//float RandomX = FMath::RandRange(MinSpawnLocation.X, MaxSpawnLocation.X);
	//float RandomY = FMath::RandRange(MinSpawnLocation.Y, MaxSpawnLocation.Y);
	//float Z = 180.0f; // Altura en Z

	//FVector SpawnLocation = FVector(RandomX, RandomY, Z);

	//AZombie* NewZombieActor3 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation, FRotator::ZeroRotator);



	FVector SpawnLocationZombie = FVector(-800.0f, 400.0f, 160.0f);

	// Crear objetos y agregarlos al vector
	// Se crean los Zombies dinamicamente
	for (int i = 0; i < 5; i++) {
		SpawnLocationZombie.X += 100;

		//Aparecion de los Zombis
		AZombie* NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);
		NuevoZombie->velocidad = FMath::FRandRange(0.1, 0.5);
		VectorZombies.Add(NuevoZombie);

	}

	//Se crean las plantas dinamicamente
	FVector SpawnLocationPlant = FVector(-800.0f, -600.0f, 160.0f);
	FVector SpawnLocationPlantTemp = SpawnLocationPlant;


	for (int i = 0; i < 5; i++) {
		SpawnLocationPlantTemp.X += 100;
		for (int j = 0; j < 2; j++) {
			SpawnLocationPlantTemp.Y += 80;
			//genera un nombre para la planta
			FString NombrePlanta = FString::Printf(TEXT("Planta %d"), i + 1);
			//crea una nueva instania para APlant
			APlant* NuevoPlant = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);
			//Asignar un Valor Aleatorio de energia a plantas
			NuevoPlant->energia = FMath::FRandRange(0.1, 0.10);

			//Muestra el mensaje por consola de el valor de la enerigia
			UE_LOG(LogTemp, Warning, TEXT("Energia de %s: %i" * NombrePlanta, NuevoPlant->energia));

			VectorPlants.Add(NuevoPlant);
			//	SpawnLocationPlant = SpawnLocationPlantTemp;
		}
		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	}

	/*MapPlantas.Add(NombrePlanta, NuevaPlanta);*/

	World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB01GameMode::aumentovelocidad, 1, true);
}

void APVZ_USFX_LAB01GameMode::aumentovelocidad()
{
	for (int i = 0, i < VectorZombies.Num(), i++)
	{

		VectorZombies[i]->velocidad = FMath::FMathRange(0.1, 0.2);
	}
}

//// Called when the game starts or when spawned
//void APVZ_USFX_LAB01GameMode::BeginPlay()
//{
//	Super::BeginPlay();
