// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FPCharacter.generated.h"

UCLASS()
class TESTPROJECT_API AFPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void HorizontalMovement(float value);
	void VerticalMovement(float value);

	void HorizontalRotation(float value);
	void VerticalRotation(float value);

	void StartRun();
	void StopRun();

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* camera;

	UCharacterMovementComponent* MovementPtr;

	float runSpeed = 900.0f;
	float walkSpeed = 600.0f;
};