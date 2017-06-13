// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "ChooseNextTask.h"



EBTNodeResult::Type UChooseNextTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	
	
	// Get PatrolPoints from PatrollingGuard
	auto AIPatrollingGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	auto PatrolPoints = AIPatrollingGuard->PatrolPoints;

	// Set the waypoint from PatrolPoints
	BlackboardComp->SetValueAsObject(NextWaypoint.SelectedKeyName, PatrolPoints[Index]);
	
	// Cycle the index
	auto CycleIndex = ++Index % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, CycleIndex);

	return EBTNodeResult::Succeeded;
}
