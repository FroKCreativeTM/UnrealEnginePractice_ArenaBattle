// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()

public : 
	AABGameMode();

public : 
	// tip. 플레이어가 게임에 입장하는 것을 로그 인이라고 한다.
	// 앞으로 이 클래스를 상송받는 것들은 이걸 거쳐갑니다.
	virtual void PostLogin(APlayerController* newPlayer) override;
};
