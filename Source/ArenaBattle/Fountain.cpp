// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = false;

	// 디폴트 객체들을 이용해서 초기화를 합니다.
	// 이 때 알수있는 점은 언리얼 엔진은 new를 사용하지 않고
	// CreateDefaultSubobject를 이용해서 객체를 생성한다는 점을 알 수 있다.
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LIGHT"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SPLASH"));
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	// 분수대 구조물을 담당할 Body 컴포넌트가 대표성을 띠므로
	// 이를 루트 컴포넌트로 지정하고
	// Water는 Body의 자식이 되게 한다.
	RootComponent = Body;
	Water->SetupAttachment(Body);
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);

	// 생성부터 특정 위치에서 생성되도록 설정한다.
	// 이 때 F가 붙은 것은 언리얼 오브젝트와 상관없는 일반 C++ 클래스 또는 구조체이다.
	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
	Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));

	// 레퍼런스 -> {오브젝트 타입}'{폴더명}/{파일명}.{에셋명}'
	// 위 경로를 이용해서 C++ 코드에 에셋을 불러오자.
	// 약간 복잡한 규칙을 가진다.
	// 먼저 ConstructorHelpers라는 클래스의 FObjectFinder를 사용해서 변수를 선언한다.
	// 이 변수에는 경로값을 전달한다.
	// 그리고 에셋의 경로는 변할 일이 없기 때문에 보통 static을 이욯새ㅓ 선언한다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT
		("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));

	// 이후 변수의 Object 멤버값을 사용하면 에셋에 대한 포인터를 가져올 수 있다.
	// 우리가 선언한 변수는 staticmesh 에셋의 포인터이므로, 이를 컴포닌터의 SetStaticMesh함수에 전달하면 C++코드로 에셋을
	// 로딩하는 기능을 완성할 수 있다.
	if (SM_BODY.Succeeded())
	{
		Body->SetStaticMesh(SM_BODY.Object);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));

	if (SM_WATER.Succeeded())
	{
		Water->SetStaticMesh(SM_WATER.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		PS_SPLASH(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));

	if (PS_SPLASH.Succeeded())
	{
		Splash->SetTemplate(PS_SPLASH.Object);
	}

	// 회전 속도 조절
	RotateSpeed = 30.f;
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();
	
	ABLOG_S(Warning);
	ABLOG(Warning, TEXT("Actor Name : %s, ID : %d, Location X : %.3f"), *GetName(), ID, GetActorLocation().X);
}

void AFountain::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	ABLOG_S(Warning);
}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 분수대 회전
	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}

