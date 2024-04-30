// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Hero/Character/HeroCharacter.h"
#include "../../Source/Runtime/Engine/Classes/Engine/DataTable.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeroCharacter() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FDataTableRowHandle();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	OUE_API UClass* Z_Construct_UClass_AGun_NoRegister();
	OUE_API UClass* Z_Construct_UClass_AHeroCharacter();
	OUE_API UClass* Z_Construct_UClass_AHeroCharacter_NoRegister();
	OUE_API UClass* Z_Construct_UClass_UHeroAnimInstance_NoRegister();
	OUE_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponDataTableRow();
	UPackage* Z_Construct_UPackage__Script_OUE();
// End Cross Module References

static_assert(std::is_polymorphic<FWeaponDataTableRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FWeaponDataTableRow cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_WeaponDataTableRow;
class UScriptStruct* FWeaponDataTableRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_WeaponDataTableRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_WeaponDataTableRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeaponDataTableRow, (UObject*)Z_Construct_UPackage__Script_OUE(), TEXT("WeaponDataTableRow"));
	}
	return Z_Registration_Info_UScriptStruct_WeaponDataTableRow.OuterSingleton;
}
template<> OUE_API UScriptStruct* StaticStruct<FWeaponDataTableRow>()
{
	return FWeaponDataTableRow::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimBP_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AnimBP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gun_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Gun;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GunLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GunLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GunRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GunRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RecoilMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RecoilMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReloadingMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadingMontage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeaponDataTableRow>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_AnimBP_MetaData[] = {
		{ "Category", "WeaponDataTableRow" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_AnimBP = { "AnimBP", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponDataTableRow, AnimBP), Z_Construct_UClass_UClass, Z_Construct_UClass_UHeroAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_AnimBP_MetaData), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_AnimBP_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_Gun_MetaData[] = {
		{ "Category", "WeaponDataTableRow" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_Gun = { "Gun", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponDataTableRow, Gun), Z_Construct_UClass_UClass, Z_Construct_UClass_AGun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_Gun_MetaData), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_Gun_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunLocation_MetaData[] = {
		{ "Category", "WeaponDataTableRow" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunLocation = { "GunLocation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponDataTableRow, GunLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunLocation_MetaData), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunLocation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunRotation_MetaData[] = {
		{ "Category", "WeaponDataTableRow" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunRotation = { "GunRotation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponDataTableRow, GunRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunRotation_MetaData), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunRotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_RecoilMontage_MetaData[] = {
		{ "Category", "WeaponDataTableRow" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_RecoilMontage = { "RecoilMontage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponDataTableRow, RecoilMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_RecoilMontage_MetaData), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_RecoilMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_ReloadingMontage_MetaData[] = {
		{ "Category", "WeaponDataTableRow" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_ReloadingMontage = { "ReloadingMontage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponDataTableRow, ReloadingMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_ReloadingMontage_MetaData), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_ReloadingMontage_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_AnimBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_Gun,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_GunRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_RecoilMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewProp_ReloadingMontage,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"WeaponDataTableRow",
		Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::PropPointers),
		sizeof(FWeaponDataTableRow),
		alignof(FWeaponDataTableRow),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FWeaponDataTableRow()
	{
		if (!Z_Registration_Info_UScriptStruct_WeaponDataTableRow.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_WeaponDataTableRow.InnerSingleton, Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_WeaponDataTableRow.InnerSingleton;
	}
	void AHeroCharacter::StaticRegisterNativesAHeroCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHeroCharacter);
	UClass* Z_Construct_UClass_AHeroCharacter_NoRegister()
	{
		return AHeroCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AHeroCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CrouchAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CrouchAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RunAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RunAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZoomAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZoomAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AimAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AimAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TriggerAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChangeFireModeAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChangeFireModeAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReloadModeAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadModeAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsCrouch_MetaData[];
#endif
		static void NewProp_IsCrouch_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsCrouch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponDataTableRowHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WeaponDataTableRowHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AimSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AimSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeroCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_OUE,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Hero/Character/HeroCharacter.h" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CrouchAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Crouch Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Crouch Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CrouchAction = { "CrouchAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, CrouchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CrouchAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CrouchAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_RunAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Run Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Run Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_RunAction = { "RunAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, RunAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_RunAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_RunAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ZoomAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Zoom Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Zoom Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ZoomAction = { "ZoomAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, ZoomAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ZoomAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ZoomAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Aim Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Aim Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimAction = { "AimAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, AimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_TriggerAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Trigger Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_TriggerAction = { "TriggerAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, TriggerAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_TriggerAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_TriggerAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ChangeFireModeAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ChangeFireMode Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ChangeFireMode Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ChangeFireModeAction = { "ChangeFireModeAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, ChangeFireModeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ChangeFireModeAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ChangeFireModeAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ReloadModeAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reload Input Action */" },
#endif
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reload Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ReloadModeAction = { "ReloadModeAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, ReloadModeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ReloadModeAction_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ReloadModeAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch_MetaData[] = {
		{ "Category", "HeroCharacter" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch_SetBit(void* Obj)
	{
		((AHeroCharacter*)Obj)->IsCrouch = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch = { "IsCrouch", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AHeroCharacter), &Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WeaponDataTableRowHandle_MetaData[] = {
		{ "Category", "HeroCharacter" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
		{ "RowType", "/Script/OUE.WeaponDataTableRow" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WeaponDataTableRowHandle = { "WeaponDataTableRowHandle", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, WeaponDataTableRowHandle), Z_Construct_UScriptStruct_FDataTableRowHandle, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WeaponDataTableRowHandle_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WeaponDataTableRowHandle_MetaData) }; // 1575649708
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimSpeed_MetaData[] = {
		{ "Category", "HeroCharacter" },
		{ "ModuleRelativePath", "Hero/Character/HeroCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimSpeed = { "AimSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHeroCharacter, AimSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimSpeed_MetaData), Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimSpeed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHeroCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_CrouchAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_RunAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ZoomAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_TriggerAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ChangeFireModeAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_ReloadModeAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_IsCrouch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WeaponDataTableRowHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_AimSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeroCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeroCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHeroCharacter_Statics::ClassParams = {
		&AHeroCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AHeroCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AHeroCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AHeroCharacter()
	{
		if (!Z_Registration_Info_UClass_AHeroCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHeroCharacter.OuterSingleton, Z_Construct_UClass_AHeroCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHeroCharacter.OuterSingleton;
	}
	template<> OUE_API UClass* StaticClass<AHeroCharacter>()
	{
		return AHeroCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeroCharacter);
	AHeroCharacter::~AHeroCharacter() {}
	struct Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics::ScriptStructInfo[] = {
		{ FWeaponDataTableRow::StaticStruct, Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics::NewStructOps, TEXT("WeaponDataTableRow"), &Z_Registration_Info_UScriptStruct_WeaponDataTableRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWeaponDataTableRow), 1539415201U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHeroCharacter, AHeroCharacter::StaticClass, TEXT("AHeroCharacter"), &Z_Registration_Info_UClass_AHeroCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHeroCharacter), 1867224647U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_4261379718(TEXT("/Script/OUE"),
		Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS