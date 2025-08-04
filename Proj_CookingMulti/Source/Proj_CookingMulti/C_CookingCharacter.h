// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "C_CookingCharacter.generated.h"

UCLASS()
class PROJ_COOKINGMULTI_API AC_CookingCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AC_CookingCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    UCameraComponent* FollowCamera;

private:
    FVector FixedCameraLocation;
    FRotator FixedCameraRotation;

    void MoveForward(float Value);
    void MoveRight(float Value);
};
