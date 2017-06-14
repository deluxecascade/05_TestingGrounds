// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingRoute.h"
#include "ChooseNextTask.h"



EBTNodeResult::Type UChooseNextTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	
	
	// Get PatrolPoints from PatrollingGuard
	auto AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto AIPatrollingRoute = AIPawn->FindComponentByClass<UPatrollingRoute>();
	if (!ensure(AIPatrollingRoute)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = AIPatrollingRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Patrol Points assigned to Patrol Route Component"))
		return EBTNodeResult::Failed;
	}

	// Set the waypoint from PatrolPoints
	BlackboardComp->SetValueAsObject(NextWaypoint.SelectedKeyName, PatrolPoints[Index]);
	
	// Cycle the index
	auto CycleIndex = ++Index % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, CycleIndex);

	return EBTNodeResult::Succeeded;
}
