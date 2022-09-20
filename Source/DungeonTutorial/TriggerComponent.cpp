// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
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
		// This will check if the ActorFound is a Uprimitive component...the goal is to turn off the physics of the statue once it is in the overlap event and have it attach to the moving actor
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(ActorFound->GetRootComponent());
		if (Component != nullptr) 
		{
			Component->SetSimulatePhysics(false);
		}
		ActorFound->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		Mover->SetShouldMove(true);
	}
	else
	{
		Mover->SetShouldMove(false);
	}
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	Mover = NewMover;

}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
		bool IsGrabbed = Actor->ActorHasTag("Grabbed");
		/*if (Actor->ActorHasTag(AcceptableActorTag) && !Actor->ActorHasTag("Grabbed")*/
		if (HasAcceptableTag && !IsGrabbed)
		{
			return Actor;
		}
	}

	return nullptr;
}
