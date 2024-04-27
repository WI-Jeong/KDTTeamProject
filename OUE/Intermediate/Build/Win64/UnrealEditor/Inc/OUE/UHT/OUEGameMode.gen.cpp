// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OUE/OUEGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOUEGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	OUE_API UClass* Z_Construct_UClass_AOUEGameMode();
	OUE_API UClass* Z_Construct_UClass_AOUEGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OUE();
// End Cross Module References
	void AOUEGameMode::StaticRegisterNativesAOUEGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOUEGameMode);
	UClass* Z_Construct_UClass_AOUEGameMode_NoRegister()
	{
		return AOUEGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AOUEGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOUEGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOUEGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOUEGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "OUEGameMode.h" },
		{ "ModuleRelativePath", "OUEGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOUEGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOUEGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOUEGameMode_Statics::ClassParams = {
		&AOUEGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOUEGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AOUEGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AOUEGameMode()
	{
		if (!Z_Registration_Info_UClass_AOUEGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOUEGameMode.OuterSingleton, Z_Construct_UClass_AOUEGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOUEGameMode.OuterSingleton;
	}
	template<> OUE_API UClass* StaticClass<AOUEGameMode>()
	{
		return AOUEGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOUEGameMode);
	AOUEGameMode::~AOUEGameMode() {}
	struct Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_OUEGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_OUEGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOUEGameMode, AOUEGameMode::StaticClass, TEXT("AOUEGameMode"), &Z_Registration_Info_UClass_AOUEGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOUEGameMode), 3045497980U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_OUEGameMode_h_1558588474(TEXT("/Script/OUE"),
		Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_OUEGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_assortrock_Team_OUE_Source_OUE_OUEGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
