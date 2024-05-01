// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Junglae/Subsystem/InventorySubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/LocalPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ULocalPlayerSubsystem();
	OUE_API UClass* Z_Construct_UClass_UInventorySubsystem();
	OUE_API UClass* Z_Construct_UClass_UInventorySubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OUE();
// End Cross Module References
	void UInventorySubsystem::StaticRegisterNativesUInventorySubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventorySubsystem);
	UClass* Z_Construct_UClass_UInventorySubsystem_NoRegister()
	{
		return UInventorySubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULocalPlayerSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySubsystem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySubsystem_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Junglae/Subsystem/InventorySubsystem.h" },
		{ "ModuleRelativePath", "Junglae/Subsystem/InventorySubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySubsystem_Statics::ClassParams = {
		&UInventorySubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventorySubsystem_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInventorySubsystem()
	{
		if (!Z_Registration_Info_UClass_UInventorySubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySubsystem.OuterSingleton, Z_Construct_UClass_UInventorySubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInventorySubsystem.OuterSingleton;
	}
	template<> OUE_API UClass* StaticClass<UInventorySubsystem>()
	{
		return UInventorySubsystem::StaticClass();
	}
	UInventorySubsystem::UInventorySubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySubsystem);
	UInventorySubsystem::~UInventorySubsystem() {}
	struct Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Subsystem_InventorySubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Subsystem_InventorySubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySubsystem, UInventorySubsystem::StaticClass, TEXT("UInventorySubsystem"), &Z_Registration_Info_UClass_UInventorySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySubsystem), 1280977549U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Subsystem_InventorySubsystem_h_2427825143(TEXT("/Script/OUE"),
		Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Subsystem_InventorySubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Subsystem_InventorySubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
