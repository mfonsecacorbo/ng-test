// Copyright Epic Games, Inc. All Rights Reserved.


#include "Proj_CookingMultiPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GI_CookingMulti.h"
#include "Blueprint/UserWidget.h"
#include "InputMappingContext.h"

AProj_CookingMultiPlayerController::AProj_CookingMultiPlayerController()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetFinder(TEXT("/Game/_Project/Widgets/Menu/WBP_MainMenu"));
    if (WidgetFinder.Succeeded())
    {
        MenuWidgetClass = WidgetFinder.Class;
    }
}

void AProj_CookingMultiPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (IsLocalController() && MenuWidgetClass != nullptr)
    {
        UUserWidget* MenuWidget = CreateWidget<UUserWidget>(this, MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();

            FInputModeUIOnly InputMode;
            InputMode.SetWidgetToFocus(MenuWidget->TakeWidget());
            InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
            SetInputMode(InputMode);
            SetShowMouseCursor(true);
        }
    }
}
void AProj_CookingMultiPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Contexts
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
