// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabThings.h"

// Sets default values for this component's properties
UGrabThings::UGrabThings()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabThings::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabThings::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator MyRotation = GetComponentRotation();
	FString RotationString = MyRotation.ToCompactString();
	UE_LOG(LogTemp, Display, TEXT("Grabber Rotation %s"), *RotationString);
}

