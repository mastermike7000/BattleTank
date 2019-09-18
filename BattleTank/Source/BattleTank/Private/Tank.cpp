// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointers as added at construction

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	// Fire = CreateDefaultSubobject<UFire>(FName("Firing Component"));


}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) {
		UE_LOG(LogTemp, Error, TEXT("No barrel reference set on %s!"), *GetName())
		return;
	}
	TankAimingComponent->SetBarrelReference(BarrelToSet);

	// Also set the local reference for spawning the projectiles
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) {
		UE_LOG(LogTemp, Error, TEXT("No turret reference set on %s!"), *GetName())
		return;
	}
	TankAimingComponent->SetTurretReference(TurretToSet);
}


void ATank::Fire()
{
	// pointer protection
	if (!Barrel) {return; }

	// Spawn a projectile at location of end of barrel socket

	// FVector SpawnLocation = Barrel->GetSocketLocation("BarrelEnd");
	// UE_LOG(LogTemp, Warning, TEXT("Spawn location for projectile: %s"), *SpawnLocation.ToString())

	auto NewProjectile = GetWorld()->SpawnActor<AProjectile>
	(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName ("BarrelEnd")),
		Barrel->GetSocketRotation(FName ("BarrelEnd"))
	);

	NewProjectile->LaunchProjectile(LaunchSpeed);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}






