// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
// #include "ABPawn.h"				// 플레이어가 조종할 수 있는 액터 즉 폰을 이용하기 위한 헤더
#include "ABCharacter.h"			// 플레이어 캐릭터 클래스
#include "ABPlayerController.h"		// 플레이어 조작계 관련 헤더

AABGameMode::AABGameMode()
{ 
	// 이 게임 모드의 폰 클래스는 ABPawn를 가져와서 설정한다.
	// DefaultPawnClass = AABPawn::StaticClass();
	// 이제 캐릭터 클래스를 이용하자.
	DefaultPawnClass = AABCharacter::StaticClass();
	// 또 이 게임의 플레이어는 ABPlayerController에 정의된 대로 이동합니다.
	PlayerControllerClass = AABPlayerController::StaticClass();
}

// 로그인을 처리하는 메서드입니다.
void AABGameMode::PostLogin(APlayerController* newPlayer)
{
	// ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(newPlayer);			// 부모 클래스에 전달
	ABLOG_S(Warning);		
}
