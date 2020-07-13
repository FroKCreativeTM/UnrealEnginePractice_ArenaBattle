// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
엔진에서는 언리얼 헤더 툴이라는 도구를 사용해서 클래스 선언을 분석하고 언리얼 실행 환경에 필요한
부가 정보들을 별도의 파일에 생성한다. 이 정보들이 담긴 파일이 바로 Fountain.generated.h 헤더 파일이다.
*/
#include "ArenaBattle.h"
#include "EngineMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"		

/*
ARENABATTLE_API의 뜻은 외부 모듈에 _declspec라는 키워드를 제공한다.
이를 사용하면 모듈명_API라는 키워드를 클래스 선언 앞에 추가한다. 
이 키워드가 없다면 다른 모듈에서 이 클래스의 사용이 불가능하다.
*/

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UPROPERTY를 사용하면 언리얼 실행환경이 객체를 자동으로 관리한다.
	// 즉 메모리를 자동으로 소멸시키기도 한다는 것이다.
	UPROPERTY(VisibleAnywhere)						
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Water;

	// 조명과 찰랑이는 이펙트이다.
	UPROPERTY(VisibleAnywhere)
	UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* Splash;

	// 객체 속성값이 int32인 
	// 이 때 UPROPERTY로 선언한다면 
	// 이 멤버 변수는 반드시 0으로 초기 값 보장을 받는다.
	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

private : 
	// AllowPrivateAccess를 true로 선언하면 
	// 언리얼 엔진에서는 접근 가능하면서 동시에 프로그래밍 영역에서는 캡슐화가 가능해진다.
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float RotateSpeed;
};