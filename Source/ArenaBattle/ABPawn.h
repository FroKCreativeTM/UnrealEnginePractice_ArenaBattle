// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "ABPawn.generated.h"

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 폰과 플레이어 컨트롤러가 생성되는 시점은 각 PostInitializeComponents를 이용해서 확인할 수 있다.
	virtual void PostInitializeComponents() override;
	// 빙의를 진행하는 시점은 폰의 PossessedBy 함수로 파악할 수 있다.
	virtual void PossessedBy(AController* newController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
