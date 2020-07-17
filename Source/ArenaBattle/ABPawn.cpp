// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPawn.h"

// Sets default values
AABPawn::AABPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 초기화
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// 루트 컴포넌트 설정 및 서브 컴포넌트 설정
	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	// 충돌점을 설정한다.
	Capsule->SetCapsuleHalfHeight(88.f);
	Capsule->SetCapsuleRadius(34.f);
	
	// 좌표계를 맞춘다.
	Mesh->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	// 3인칭 카메라를 설정한다.
	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

	// 메시 컴포넌트를 불러온다.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> 
		SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));

	if (SK_CARDBOARD.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	// 블루 프린트를 이용해서 애니메이션 실행
	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM
	(TEXT("/Game/Book/Animation/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));

	if (WARRIOR_ANIM.Succeeded())
	{
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}
}

void AABPawn::UpDown(float newAxisValue)
{
	//ABLOG(Warning, TEXT("%f"), newAxisValue);
	
	// 움직임에 대응하는 벡터를 가져와 새로운 밸류값을 적용한다.
	AddMovementInput(GetActorForwardVector(), newAxisValue);	
}

void AABPawn::LeftRight(float newAxisValue)
{
	//ABLOG(Warning, TEXT("%f"), newAxisValue);

	// 움직임에 대응하는 벡터를 가져와 새로운 밸류값을 적용한다.
	AddMovementInput(GetActorRightVector(), newAxisValue);
}

// Called when the game starts or when spawned
void AABPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// 게임이 시작되면, 즉 이 폰이 실행되면 바로 애니메이션을 불러와서 이 폰에 적용한다.
	// 단 이 방법은 프로젝트가 커지면 한계가 온다.
	// 이를 막기위해 쓰는 것이 바로 애니메이션 블루프린트이다
	//Mesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	//UAnimationAsset* AnimeAsset = LoadObject<UAnimationAsset>
	//	(nullptr, TEXT("/Game/Book/Animation/WarriorRun.WarriorRun"));

	//if (AnimeAsset != nullptr)
	//{
	//	ABLOG(Warning, TEXT("Load Asset is success"));
	//	Mesh->PlayAnimation(AnimeAsset, true);
	//}


}

// Called every frame
void AABPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPawn::PossessedBy(AController* newController)
{
	ABLOG_S(Warning);
	Super::PossessedBy(newController);
}

// Called to bind functionality to input
void AABPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 이미 프로젝트 세팅에서 한 기능과 입력 메서드를 바인딩한다.
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABPawn::LeftRight);
}

