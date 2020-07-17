// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public : 
	// 충돌 검사 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent* Capsule;

	// 캐릭터 에셋 + 애니메이션 컴포넌트 (좌표계는 에셋을 만들 때 사용한 좌표계와 언리얼 좌표계를 맞게 설정할 필요가 있다.
	UPROPERTY(VisibleAnywhere, Category = Vision)
	USkeletalMeshComponent* Mesh;

	// 입력에 따라 캐릭터가 움직이도록 설정하는 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement* Movement;

	// 3인칭 시점에서 카메라 구도를 편하게 설정할 수 있는 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	// 폰에 부착된 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

public:
	// Sets default values for this pawn's properties
	AABPawn();

private : 
	// 조작계 관련 부분
	void UpDown(float newAxisValue);
	void LeftRight(float newAxisValue);

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
