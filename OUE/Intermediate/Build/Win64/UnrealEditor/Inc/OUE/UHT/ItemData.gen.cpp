// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Junglae/Item/ItemData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemData() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	OUE_API UClass* Z_Construct_UClass_UItem_NoRegister();
	OUE_API UScriptStruct* Z_Construct_UScriptStruct_FItemData();
	UPackage* Z_Construct_UPackage__Script_OUE();
// End Cross Module References

static_assert(std::is_polymorphic<FItemData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FItemData cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ItemData;
class UScriptStruct* FItemData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ItemData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ItemData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemData, (UObject*)Z_Construct_UPackage__Script_OUE(), TEXT("ItemData"));
	}
	return Z_Registration_Info_UScriptStruct_ItemData.OuterSingleton;
}
template<> OUE_API UScriptStruct* StaticStruct<FItemData>()
{
	return FItemData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FItemData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemImage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemImage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemDesc_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_ItemDesc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BundleCount_MetaData[];
#endif
		static const UECodeGen_Private::FUInt32PropertyParams NewProp_BundleCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemFunctionClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ItemFunctionClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Junglae/Item/ItemData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FItemData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemImage_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Junglae/Item/ItemData.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemImage = { "ItemImage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemData, ItemImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemImage_MetaData), Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemImage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemDesc_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Junglae/Item/ItemData.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemDesc = { "ItemDesc", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemData, ItemDesc), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemDesc_MetaData), Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemDesc_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_BundleCount_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Junglae/Item/ItemData.h" },
	};
#endif
	const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_BundleCount = { "BundleCount", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemData, BundleCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_BundleCount_MetaData), Z_Construct_UScriptStruct_FItemData_Statics::NewProp_BundleCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemFunctionClass_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Junglae/Item/ItemData.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemFunctionClass = { "ItemFunctionClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemData, ItemFunctionClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemFunctionClass_MetaData), Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemFunctionClass_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemImage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemDesc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_BundleCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ItemFunctionClass,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"ItemData",
		Z_Construct_UScriptStruct_FItemData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::PropPointers),
		sizeof(FItemData),
		alignof(FItemData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FItemData()
	{
		if (!Z_Registration_Info_UScriptStruct_ItemData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ItemData.InnerSingleton, Z_Construct_UScriptStruct_FItemData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ItemData.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Item_ItemData_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Item_ItemData_h_Statics::ScriptStructInfo[] = {
		{ FItemData::StaticStruct, Z_Construct_UScriptStruct_FItemData_Statics::NewStructOps, TEXT("ItemData"), &Z_Registration_Info_UScriptStruct_ItemData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FItemData), 4226282209U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Item_ItemData_h_3088753708(TEXT("/Script/OUE"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Item_ItemData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OUE_Source_OUE_Junglae_Item_ItemData_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
