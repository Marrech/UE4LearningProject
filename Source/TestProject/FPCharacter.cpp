// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter.h"

// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->AttachTo(RootComponent);
	camera->SetRelativeLocation(FVector(0, 0, 40));
	MovementPtr = Cast<UCharacterMovementComponent>(GetCharacterMovement());
}

// Called when the game starts or when spawned
void AFPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Run", IE_Pressed, this, &AFPCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &AFPCharacter::StopRun);

	InputComponent->BindAxis("Horizontal", this, &AFPCharacter::HorizontalMovement);
	InputComponent->BindAxis("Vertical", this, &AFPCharacter::VerticalMovement);

	InputComponent->BindAxis("HRotation", this, &AFPCharacter::HorizontalRotation);
	InputComponent->BindAxis("VRotation", this, &AFPCharacter::VerticalRotation);
}

void AFPCharacter::HorizontalMovement(float value) 
{
	if (value) 
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AFPCharacter::VerticalMovement(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void AFPCharacter::HorizontalRotation(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void AFPCharacter::VerticalRotation(float value)
{
	if (value)
	{
		float temp = camera->GetRelativeRotation().Pitch + value;

		if (temp < 70 && temp > -70) 
		{
			camera->AddLocalRotation(FRotator(value, 0, 0));
		}
	}
}

void AFPCharacter::StartRun()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Start");
	MovementPtr->MaxWalkSpeed = runSpeed;
}

void AFPCharacter::StopRun()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Stop");
	MovementPtr->MaxWalkSpeed = walkSpeed;
}
