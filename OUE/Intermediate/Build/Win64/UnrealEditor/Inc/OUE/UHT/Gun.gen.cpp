// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Hero/Gun/Gun.h"
#include "../../Source/Runtime/Engine/Classes/Engine/DataTable.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGun() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UChildActorComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FDataTableRowHandle();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	OUE_API UClass* Z_Construct_UClass_AGun();
	OUE_API UClass* Z_Construct_UClass_AGun_NoRegister();
	OUE_API UScriptStruct* Z_Construct_UScriptStruct_FGunDataTableRow();
	UPackage* Z_Construct_UPackage__Script_OUE();
// End Cross Module References

static_assert(std::is_polymorphic<FGunDataTableRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FGunDataTableRow cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GunDataTableRow;
class UScriptStruct* FGunDataTableRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GunDataTableRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GunDataTableRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGunDataTableRow, (UObject*)Z_Construct_UPackage__Script_OUE(), TEXT("GunDataTableRow"));
	}
	return Z_Registration_Info_UScriptStruct_GunDataTableRow.OuterSingleton;
}
template<> OUE_API UScriptStruct* StaticStruct<FGunDataTableRow>()
{
	return FGunDataTableRow::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGunDataTableRow_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FireDelay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmo_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireEffect_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FireEffect;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunDataTableRow_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGunDataTableRow>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireDelay_MetaData[] = {
		{ "Category", "GunDataTableRow" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireDelay = { "FireDelay", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGunDataTableRow, FireDelay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireDelay_MetaData), Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireDelay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_MaxAmmo_MetaData[] = {
		{ "Category", "GunDataTableRow" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGunDataTableRow, MaxAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_MaxAmmo_MetaData), Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_MaxAmmo_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireEffect_MetaData[] = {
		{ "Category", "GunDataTableRow" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireEffect = { "FireEffect", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGunDataTableRow, FireEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireEffect_MetaData), Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireEffect_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGunDataTableRow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireDelay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_MaxAmmo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewProp_FireEffect,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGunDataTableRow_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"GunDataTableRow",
		Z_Construct_UScriptStruct_FGunDataTableRow_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunDataTableRow_Statics::PropPointers),
		sizeof(FGunDataTableRow),
		alignof(FGunDataTableRow),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunDataTableRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGunDataTableRow_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGunDataTableRow_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FGunDataTableRow()
	{
		if (!Z_Registration_Info_UScriptStruct_GunDataTableRow.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GunDataTableRow.InnerSingleton, Z_Construct_UScriptStruct_FGunDataTableRow_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GunDataTableRow.InnerSingleton;
	}
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SkeletalMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChildActorComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChildActorComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BulletDataTableRowHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BulletDataTableRowHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GunDataTableRowHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GunDataTableRowHandle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGun_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Hero/Gun/Gun.h" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb7\xef\xbf\xbd\xc5\xbb \xef\xbf\xbd\xde\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xbc\xef\xbf\xbd \xef\xbf\xbd\xd1\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc3\xa3\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc5\xb1\xe2\xbc\xad \xef\xbf\xbd\xef\xbf\xbd\xc8\xaf\xef\xbf\xbd\xcf\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb7\xef\xbf\xbd\xc5\xbb \xef\xbf\xbd\xde\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xbc\xef\xbf\xbd \xef\xbf\xbd\xd1\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc3\xa3\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc5\xb1\xe2\xbc\xad \xef\xbf\xbd\xef\xbf\xbd\xc8\xaf\xef\xbf\xbd\xcf\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent = { "SkeletalMeshComponent", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, SkeletalMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent_MetaData[] = {
		{ "Category", "Gun" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent = { "ChildActorComponent", nullptr, (EPropertyFlags)0x0020080000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, ChildActorComponent), Z_Construct_UClass_UChildActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_BulletDataTableRowHandle_MetaData[] = {
		{ "Category", "Gun" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_BulletDataTableRowHandle = { "BulletDataTableRowHandle", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, BulletDataTableRowHandle), Z_Construct_UScriptStruct_FDataTableRowHandle, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_BulletDataTableRowHandle_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_BulletDataTableRowHandle_MetaData) }; // 1575649708
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGun_Statics::NewProp_GunDataTableRowHandle_MetaData[] = {
		{ "Category", "Gun" },
		{ "ModuleRelativePath", "Hero/Gun/Gun.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGun_Statics::NewProp_GunDataTableRowHandle = { "GunDataTableRowHandle", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGun, GunDataTableRowHandle), Z_Construct_UScriptStruct_FDataTableRowHandle, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGun_Statics::NewProp_GunDataTableRowHandle_MetaData), Z_Construct_UClass_AGun_Statics::NewProp_GunDataTableRowHandle_MetaData) }; // 1575649708
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGun_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_SkeletalMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_ChildActorComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_BulletDataTableRowHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGun_Statics::NewProp_GunDataTableRowHandle,
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
	template<> OUE_API UClass* StaticClass<AGun>()
	{
		return AGun::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGun);
	AGun::~AGun() {}
	struct Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics::ScriptStructInfo[] = {
		{ FGunDataTableRow::StaticStruct, Z_Construct_UScriptStruct_FGunDataTableRow_Statics::NewStructOps, TEXT("GunDataTableRow"), &Z_Registration_Info_UScriptStruct_GunDataTableRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGunDataTableRow), 1597882774U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGun, AGun::StaticClass, TEXT("AGun"), &Z_Registration_Info_UClass_AGun, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGun), 960664544U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_3853816257(TEXT("/Script/OUE"),
		Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Gun_Gun_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
