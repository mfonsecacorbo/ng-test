// Fill out your copyright notice in the Description page of Project Settings.


#include "C_CookingCharacter.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AC_CookingCharacter::AC_CookingCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    bUseControllerRotationYaw = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 0.f;
    CameraBoom->bUsePawnControlRotation = false;
    CameraBoom->SetRelativeRotation(FRotator(-65.f, 0.f, 0.f));

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    FixedCameraLocation = FVector(-886.170057f, 0.000096f, 2507.575403f);
    FixedCameraRotation = FRotator(-69.999999f, 0.f, 0.f);
}

// Called when the game starts or when spawned
void AC_CookingCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority() || IsLocallyControlled())
    {
        FixedCameraLocation = FVector(-886.170057f, 0.000096f, 2507.575403f);
        FixedCameraRotation = FRotator(-69.999999f, 0.f, 0.f);

        CameraBoom->SetWorldLocation(FixedCameraLocation);
        CameraBoom->SetWorldRotation(FixedCameraRotation);
    }
}

// Called every frame
void AC_CookingCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority() || IsLocallyControlled())
    {

        CameraBoom->SetWorldLocation(FixedCameraLocation);
        CameraBoom->SetWorldRotation(FixedCameraRotation);
    }
}

void AC_CookingCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}


void AC_CookingCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}


void AC_CookingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AC_CookingCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AC_CookingCharacter::MoveRight);
}