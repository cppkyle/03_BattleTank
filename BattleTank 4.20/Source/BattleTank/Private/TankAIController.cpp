// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("%s does not control anything!"), *this->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling %s"), *this->GetName(), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("%s does not find the Player Tank!"), *this->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s detected %s"), *this->GetName(), *PlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaSeconds) {

	Super::Tick(DeltaSeconds);
	auto PlayerTank = GetPlayerTank();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("%s can't access ControlledTank!"), *this->GetName());
	}
	else if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("%s can't access PlayerTank!"), *this->GetName());
	}
	else {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


