// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattle/Fountain.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFountain() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AFountain_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_AFountain();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
	ENGINE_API UClass* Z_Construct_UClass_URotatingMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AFountain::StaticRegisterNativesAFountain()
	{
	}
	UClass* Z_Construct_UClass_AFountain_NoRegister()
	{
		return AFountain::StaticClass();
	}
	struct Z_Construct_UClass_AFountain_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotateSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RotateSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Movement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Movement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Splash_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Splash;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Light_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Light;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Water_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Water;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Body;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFountain_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Fountain.h" },
		{ "ModuleRelativePath", "Fountain.h" },
		{ "ToolTip", "ARENABATTLE_API?? ???? ?\xdc\xba? ???\xe2\xbf\xa1 _declspec???? \xc5\xb0???\xe5\xb8\xa6 ?????\xd1\xb4?.\n?\xcc\xb8? ?????\xcf\xb8? ??????_API???? \xc5\xb0???\xe5\xb8\xa6 \xc5\xac???? ???? ?\xd5\xbf? ?\xdf\xb0??\xd1\xb4?.\n?? \xc5\xb0???\xe5\xb0\xa1 ???\xd9\xb8? ?\xd9\xb8? ???\xe2\xbf\xa1?? ?? \xc5\xac?????? ?????? ?\xd2\xb0????\xcf\xb4?." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Fountain.h" },
		{ "ToolTip", "AllowPrivateAccess?? true?? ?????\xcf\xb8?\n?\xf0\xb8\xae\xbe? ?????? ???? ?????\xcf\xb8\xe9\xbc\xad ???\xc3\xbf? ???\xce\xb1\xd7\xb7??? ?????????? \xc4\xb8??\xc8\xad?? ??????????." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed = { "RotateSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, RotateSpeed), METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Movement_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Movement), Z_Construct_UClass_URotatingMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Movement_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Movement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "ID" },
		{ "ModuleRelativePath", "Fountain.h" },
		{ "ToolTip", "??\xc3\xbc ?\xd3\xbc????? int32??\n?? ?? UPROPERTY?? ?????\xd1\xb4\xd9\xb8?\n?? ???? ?????? ?\xdd\xb5??? 0???? ?\xca\xb1? ?? ?????? ?\xde\xb4\xc2\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, ID), METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_ID_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_ID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Splash_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Splash = { "Splash", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Splash), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Splash_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Splash_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Light_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
		{ "ToolTip", "?????? ?????\xcc\xb4? ????\xc6\xae?\xcc\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Light = { "Light", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Light), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Light_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Light_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Water_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Water = { "Water", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Water), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Water_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Water_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Body_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
		{ "ToolTip", "UPROPERTY?? ?????\xcf\xb8? ?\xf0\xb8\xae\xbe? ????\xc8\xaf???? ??\xc3\xbc?? ?\xda\xb5????? ?????\xd1\xb4?.\n?? ?\xde\xb8\xf0\xb8\xae\xb8? ?\xda\xb5????? ?\xd2\xb8???\xc5\xb0?\xe2\xb5\xb5 ?\xd1\xb4\xd9\xb4? ???\xcc\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Body), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Body_MetaData, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Body_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFountain_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Movement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_ID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Splash,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Light,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Water,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Body,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFountain_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFountain>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFountain_Statics::ClassParams = {
		&AFountain::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFountain_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFountain()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFountain_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFountain, 415151323);
	template<> ARENABATTLE_API UClass* StaticClass<AFountain>()
	{
		return AFountain::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFountain(Z_Construct_UClass_AFountain, &AFountain::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AFountain"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFountain);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
