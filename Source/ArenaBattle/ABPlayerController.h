// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 폰의 조종부를 선언합니다.
 */
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected : 
	// 일일히 뷰포트를 눌러서 윈도우를 고정해야 인풋이 들어오는 문제를 일단 해제하는 기능
	virtual void BeginPlay() override;

public :
	// 폰과 플레이어 컨트롤러가 생성되는 시점은 각 PostInitializeComponents를 이용해서 확인할 수 있다.
	virtual void PostInitializeComponents() override;
	// 빙의를 진행하는 시점은 컨트롤러의 OnPossess 함수로 파악할 수 있다.
	// 참고로 책에는 Possess로 되어있는데 이는 final로 변경되었고
	// 이와 같은 역활을 하는 OnPossess를 이용해서 진행할 것이다. (4.22)
	virtual void OnPossess(APawn* aPawn) override;	
};
