// Fill out your copyright notice in the Description page of Project Settings.


#include "CookingCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACookingCharacter::ACookingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->bOrientRotationToMovement = false;
    bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void ACookingCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACookingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACookingCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        AddMovementInput(FVector::ForwardVector, Value);
    }
}

void ACookingCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        AddMovementInput(FVector::RightVector, Value);
    }
}

// Called to bind functionality to input
void ACookingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ACookingCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACookingCharacter::MoveRight);

}
