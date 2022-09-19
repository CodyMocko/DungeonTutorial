// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when 
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Component works!"));
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* ActorFound = GetAcceptableActor();

	if (ActorFound != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unlocking"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Relocking"));
	}
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag))
		{
			return Actor;
		}
	}

	return nullptr;
}
