// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Shoot();
	void OnWalk();
	void OnStopWalk();
	void OnSprint();
	void OnStopSprint();
	bool bIsWalking;
	bool bIsJogging;
	bool bIsSprinting;
	bool bIsMovingRight;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY(EditAnywhere, Category = Modifiers)
	float WalkSpeed = 0.25;

	UPROPERTY(EditAnywhere, Category = Modifiers)
	float JogSpeed = 0.7;

	UPROPERTY(EditAnywhere, Category = Modifiers)
	float SprintSpeed = 1;
	// SprintSpeed is unnecessary  
};
