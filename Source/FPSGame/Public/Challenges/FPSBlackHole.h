// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "FPSBlackHole.generated.h"

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackHole();

protected:

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category= "Components")
	UStaticMeshComponent* MeshComp;

	/* Inner sphere destroys the overlapping components */
	UPROPERTY(VisibleAnywhere, Category= "Components")
	USphereComponent* InnerSphereComponent;

	/* Outer sphere pull components (that are physically simulating) toward th centre of the actor */
	UPROPERTY(VisibleAnywhere, Category= "Components")
	USphereComponent* OuterSphereComponent;

	// Marked with UFUNCTION to bind to overlap event
	UFUNCTION()
	void OverlapInnerSphere(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
