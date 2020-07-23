// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacter.h"

// Sets default values
AABCharacter::AABCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 메모리 할당
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	// 캐릭터 생성과 동시에 설정할 부분
	// 좌표계를 맞춘다.
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	// 3인칭 카메라를 설정한다.
	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

	// 메시 컴포넌트를 불러온다.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));

	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	// 블루 프린트를 이용해서 애니메이션 실행
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM
	(TEXT("/Game/Book/Animation/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));

	if (WARRIOR_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}

	SetControlMode(EControlMode::ECM_DIABLO);

	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed = 10.0f;
}

// Called when the game starts or when spawned
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AABCharacter::SetControlMode(EControlMode NewControlMode)
{
	CurrentControlMode = NewControlMode;

	switch (NewControlMode)
	{
	// GTA 스타일 컨트롤러
	case AABCharacter::EControlMode::ECM_GTA:
		// SpringArm->TargetArmLength = 450.0f;		// 카메리 지지대 길이는 450cm
		// SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		ArmLengthTo = 450.0f;
		ArmRotationTo = FRotator::ZeroRotator;

		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	case AABCharacter::EControlMode::ECM_DIABLO:
		// SpringArm->TargetArmLength = 800.0f;		// 카메리 지지대 길이는 800cm
		// SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));	// 45도 내려다 봄
		ArmLengthTo = 800.0f;
		ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);

		// 회전없이 항상 고정 시선으로 
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bInheritPitch = false;			
		SpringArm->bInheritRoll = false;
		SpringArm->bInheritYaw = false;
		SpringArm->bDoCollisionTest = false;	// 카메라 줌 없이 카메라와 캐릭터 사이에 장애물이 없는 경우 외곽선으로 처리
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	default:
		break;
	}
}

// Called every frame
void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	// 컨트롤 모드가 디아블로인 경우
	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_DIABLO:
		// 
		//if (DirectionToMove.SizeSquared() > 0.0f)
		//{
			// GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			SpringArm->RelativeRotation = FMath::RInterpTo(SpringArm->RelativeRotation, ArmRotationTo, DeltaTime, ArmRotationSpeed);
			// AddMovementInput(DirectionToMove);
		//}
		break;
	}

	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_DIABLO:
		 
		if (DirectionToMove.SizeSquared() > 0.0f)
		{
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
		}
		break;
	}
}

// Called to bind functionality to input
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AABCharacter::ViewChange);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AABCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);
}

void AABCharacter::UpDown(float newAxisValue)
{
	// AddMovementInput(GetActorForwardVector(), newAxitValue);

	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_GTA:
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), newAxisValue);
		break;
	case AABCharacter::EControlMode::ECM_DIABLO:
		DirectionToMove.X = newAxisValue;
		break;
	}	
}

void AABCharacter::LeftRight(float newAxisValue)
{
	// AddMovementInput(GetActorRightVector(), newAxisValue);

	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_GTA:
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), newAxisValue);
		break;
	case AABCharacter::EControlMode::ECM_DIABLO:
		DirectionToMove.Y = newAxisValue;
		break;
	}
}

void AABCharacter::LookUp(float newAxisValue)
{

	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_GTA:
		AddControllerPitchInput(newAxisValue);
		break;
	}
}

void AABCharacter::Turn(float newAxisValue)
{
	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_GTA:
		AddControllerYawInput(newAxisValue);
		break;
	}
}

void AABCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case AABCharacter::EControlMode::ECM_GTA:
		GetController()->SetControlRotation(GetActorRotation());
		CurrentControlMode = EControlMode::ECM_DIABLO;
		break;
	case AABCharacter::EControlMode::ECM_DIABLO:
		GetController()->SetControlRotation(SpringArm->RelativeRotation);
		CurrentControlMode = EControlMode::ECM_GTA;
		break;
	}
}

