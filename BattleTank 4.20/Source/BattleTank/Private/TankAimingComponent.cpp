// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UTankAimingComponent::AimAt(FVector TargetLocation, float LaunchSpeed) {

	if (!Barrel) { return; }
	FVector TossVelocity;
	TArray<AActor*> Ignored;
	Ignored.Add(this->GetOwner());
	if (UGameplayStatics::SuggestProjectileVelocity
	(
		Barrel,
		TossVelocity,
		Barrel->GetSocketLocation(),
		TargetLocation,
		LaunchSpeed,
		false,
		100,
		0,
		ESuggestProjVelocityTraceOption::TraceFullPath,
		FCollisionResponseParams::DefaultResponseParam,
		Ignored,
		true
	)) {

		UE_LOG(LogTemp, Log, TEXT("Firing at direction %s"), *TossVelocity.ToString());

	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Cannot Aim!"), LaunchSpeed);
	}


}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {

	Barrel = BarrelToSet;

}