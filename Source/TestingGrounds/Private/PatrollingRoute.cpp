// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "PatrollingRoute.h"


// Sets default values for this component's properties
UPatrollingRoute::UPatrollingRoute()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPatrollingRoute::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPatrollingRoute::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<AActor*> UPatrollingRoute::GetPatrolPoints()
{
	return PatrolPoints;
}