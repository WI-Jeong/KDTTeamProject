// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyClass/Actors/Enemy/Enemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	HELLDIVER_API UClass* Z_Construct_UClass_AEnemy();
	HELLDIVER_API UClass* Z_Construct_UClass_AEnemy_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HellDiver();
// End Cross Module References
	void AEnemy::StaticRegisterNativesAEnemy()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemy);
	UClass* Z_Construct_UClass_AEnemy_NoRegister()
	{
		return AEnemy::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SkeletalMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CapsuleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CapsuleComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HP_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HP;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_HellDiver,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyClass/Actors/Enemy/Enemy.h" },
		{ "ModuleRelativePath", "MyClass/Actors/Enemy/Enemy.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_SkeletalMeshComponent_MetaData[] = {
		{ "Category", "Enemy" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClass/Actors/Enemy/Enemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_SkeletalMeshComponent = { "SkeletalMeshComponent", nullptr, (EPropertyFlags)0x0020080000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemy, SkeletalMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_SkeletalMeshComponent_MetaData), Z_Construct_UClass_AEnemy_Statics::NewProp_SkeletalMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_CapsuleComponent_MetaData[] = {
		{ "Category", "Enemy" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClass/Actors/Enemy/Enemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_CapsuleComponent = { "CapsuleComponent", nullptr, (EPropertyFlags)0x0020080000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemy, CapsuleComponent), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_CapsuleComponent_MetaData), Z_Construct_UClass_AEnemy_Statics::NewProp_CapsuleComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_HP_MetaData[] = {
		{ "Category", "Enemy" },
		{ "ModuleRelativePath", "MyClass/Actors/Enemy/Enemy.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_HP = { "HP", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemy, HP), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_HP_MetaData), Z_Construct_UClass_AEnemy_Statics::NewProp_HP_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_SkeletalMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_CapsuleComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_HP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Statics::ClassParams = {
		&AEnemy::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEnemy_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AEnemy()
	{
		if (!Z_Registration_Info_UClass_AEnemy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemy.OuterSingleton, Z_Construct_UClass_AEnemy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEnemy.OuterSingleton;
	}
	template<> HELLDIVER_API UClass* StaticClass<AEnemy>()
	{
		return AEnemy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy);
	AEnemy::~AEnemy() {}
	struct Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Enemy_Enemy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Enemy_Enemy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEnemy, AEnemy::StaticClass, TEXT("AEnemy"), &Z_Registration_Info_UClass_AEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemy), 4129179115U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Enemy_Enemy_h_3658690530(TEXT("/Script/HellDiver"),
		Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Enemy_Enemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Enemy_Enemy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
