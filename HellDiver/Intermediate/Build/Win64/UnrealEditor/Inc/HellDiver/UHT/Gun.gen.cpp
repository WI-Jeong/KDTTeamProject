// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyClass/Actors/Gun/Gun.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGun() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UChildActorComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	HELLDIVER_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	HELLDIVER_API UClass* Z_Construct_UClass_AGun();
	HELLDIVER_API UClass* Z_Construct_UClass_AGun_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HellDiver();
// End Cross Module References
	void AGun::StaticRegisterNativesAGun()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGun);
	UClass* Z_Construct_UClass_AGun_NoRegister()
	{
		return AGun::StaticClass();
	}
	struct Z_Construct_UClass_AGun_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bullet_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Bullet;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SkeletalMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FireSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChildActorComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChildActorComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FireDelay;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGun_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_HellDiver,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyClass/Actors/Gun/Gun.h" },
		{ "ModuleRelativePath", "MyClass/Actors/Gun/Gun.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_Bullet_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gun */" },
#endif
		{ "ModuleRelativePath", "MyClass/Actors/Gun/Gun.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gun" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_Bullet = { "Bullet", nullptr, (EPropertyFlags)0x0044000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, Bullet), Z_Construct_UClass_UClass, Z_Construct_UClass_ABullet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_Bullet_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_Bullet_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\xb4\x9d \xec\x8a\xa4\xec\xbc\x88\xeb\xa0\x88\xed\x83\x88 \xeb\xa9\x94\xec\x89\xac\xea\xb0\x80\xec\xa0\xb8\xec\x99\x80\xec\x84\x9c \xec\xb4\x9d\xea\xb5\xac \xec\x86\x8c\xec\xbc\x93 \xec\xb0\xbe\xec\x9d\x80\xeb\x8b\xa4\xec\x9d\x8c \xea\xb1\xb0\xea\xb8\xb0\xec\x84\x9c \xec\x86\x8c\xed\x99\x98\xed\x95\x98\xeb\x8f\x84\xeb\xa1\x9d\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClass/Actors/Gun/Gun.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb4\x9d \xec\x8a\xa4\xec\xbc\x88\xeb\xa0\x88\xed\x83\x88 \xeb\xa9\x94\xec\x89\xac\xea\xb0\x80\xec\xa0\xb8\xec\x99\x80\xec\x84\x9c \xec\xb4\x9d\xea\xb5\xac \xec\x86\x8c\xec\xbc\x93 \xec\xb0\xbe\xec\x9d\x80\xeb\x8b\xa4\xec\x9d\x8c \xea\xb1\xb0\xea\xb8\xb0\xec\x84\x9c \xec\x86\x8c\xed\x99\x98\xed\x95\x98\xeb\x8f\x84\xeb\xa1\x9d" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent = { "SkeletalMeshComponent", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, SkeletalMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_FireSound_MetaData[] = {
		{ "Category", "Gun" },
		{ "ModuleRelativePath", "MyClass/Actors/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_FireSound_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_FireSound_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent_MetaData[] = {
		{ "Category", "Gun" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClass/Actors/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent = { "ChildActorComponent", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, ChildActorComponent), Z_Construct_UClass_UChildActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_FireDelay_MetaData[] = {
		{ "Category", "Gun" },
		{ "ModuleRelativePath", "MyClass/Actors/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_FireDelay = { "FireDelay", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, FireDelay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_FireDelay_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_FireDelay_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGun_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_Bullet,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_FireSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_FireDelay,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGun_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGun>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGun_Statics::ClassParams = {
		&AGun::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGun_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::Class_MetaDataParams), Z_Construct_UClass_AGun_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AGun()
	{
		if (!Z_Registration_Info_UClass_AGun.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGun.OuterSingleton, Z_Construct_UClass_AGun_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGun.OuterSingleton;
	}
	template<> HELLDIVER_API UClass* StaticClass<AGun>()
	{
		return AGun::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGun);
	AGun::~AGun() {}
	struct Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Gun_Gun_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Gun_Gun_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGun, AGun::StaticClass, TEXT("AGun"), &Z_Registration_Info_UClass_AGun, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGun), 39377315U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Gun_Gun_h_3022005454(TEXT("/Script/HellDiver"),
		Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Gun_Gun_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HellDiver_Source_HellDiver_MyClass_Actors_Gun_Gun_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
