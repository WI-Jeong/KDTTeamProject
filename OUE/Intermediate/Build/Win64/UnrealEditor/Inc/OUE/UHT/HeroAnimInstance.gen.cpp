// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Hero/Character/AnimInstance/HeroAnimInstance.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeroAnimInstance() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	OUE_API UClass* Z_Construct_UClass_UHeroAnimInstance();
	OUE_API UClass* Z_Construct_UClass_UHeroAnimInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OUE();
// End Cross Module References
	void UHeroAnimInstance::StaticRegisterNativesUHeroAnimInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHeroAnimInstance);
	UClass* Z_Construct_UClass_UHeroAnimInstance_NoRegister()
	{
		return UHeroAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UHeroAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsFalling_MetaData[];
#endif
		static void NewProp_IsFalling_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsFalling;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Velocity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsShouldMove_MetaData[];
#endif
		static void NewProp_IsShouldMove_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsShouldMove;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHeroAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHeroAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Hero/Character/AnimInstance/HeroAnimInstance.h" },
		{ "ModuleRelativePath", "Hero/Character/AnimInstance/HeroAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "Category", "HeroAnimInstance" },
		{ "ModuleRelativePath", "Hero/Character/AnimInstance/HeroAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHeroAnimInstance, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Speed_MetaData), Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling_MetaData[] = {
		{ "Category", "HeroAnimInstance" },
		{ "ModuleRelativePath", "Hero/Character/AnimInstance/HeroAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling_SetBit(void* Obj)
	{
		((UHeroAnimInstance*)Obj)->IsFalling = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling = { "IsFalling", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHeroAnimInstance), &Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling_MetaData), Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Velocity_MetaData[] = {
		{ "Category", "HeroAnimInstance" },
		{ "ModuleRelativePath", "Hero/Character/AnimInstance/HeroAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHeroAnimInstance, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Velocity_MetaData), Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Velocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove_MetaData[] = {
		{ "Category", "HeroAnimInstance" },
		{ "ModuleRelativePath", "Hero/Character/AnimInstance/HeroAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove_SetBit(void* Obj)
	{
		((UHeroAnimInstance*)Obj)->IsShouldMove = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove = { "IsShouldMove", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHeroAnimInstance), &Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove_MetaData), Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHeroAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsFalling,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_Velocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHeroAnimInstance_Statics::NewProp_IsShouldMove,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHeroAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHeroAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHeroAnimInstance_Statics::ClassParams = {
		&UHeroAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHeroAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UHeroAnimInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHeroAnimInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHeroAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UHeroAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHeroAnimInstance.OuterSingleton, Z_Construct_UClass_UHeroAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHeroAnimInstance.OuterSingleton;
	}
	template<> OUE_API UClass* StaticClass<UHeroAnimInstance>()
	{
		return UHeroAnimInstance::StaticClass();
	}
	UHeroAnimInstance::UHeroAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHeroAnimInstance);
	UHeroAnimInstance::~UHeroAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_Hero_Character_AnimInstance_HeroAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_Hero_Character_AnimInstance_HeroAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHeroAnimInstance, UHeroAnimInstance::StaticClass, TEXT("UHeroAnimInstance"), &Z_Registration_Info_UClass_UHeroAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHeroAnimInstance), 4070689934U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_Hero_Character_AnimInstance_HeroAnimInstance_h_293264402(TEXT("/Script/OUE"),
		Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_Hero_Character_AnimInstance_HeroAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_Hero_Character_AnimInstance_HeroAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS