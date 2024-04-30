// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Hero/Character/HeroCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OUE_HeroCharacter_generated_h
#error "HeroCharacter.generated.h already included, missing '#pragma once' in HeroCharacter.h"
#endif
#define OUE_HeroCharacter_generated_h

#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_21_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeaponDataTableRow_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> OUE_API UScriptStruct* StaticStruct<struct FWeaponDataTableRow>();

#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_SPARSE_DATA
#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_ACCESSORS
#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHeroCharacter(); \
	friend struct Z_Construct_UClass_AHeroCharacter_Statics; \
public: \
	DECLARE_CLASS(AHeroCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OUE"), NO_API) \
	DECLARE_SERIALIZER(AHeroCharacter)


#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroCharacter(AHeroCharacter&&); \
	NO_API AHeroCharacter(const AHeroCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHeroCharacter) \
	NO_API virtual ~AHeroCharacter();


#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_39_PROLOG
#define FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_SPARSE_DATA \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_ACCESSORS \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_INCLASS_NO_PURE_DECLS \
	FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OUE_API UClass* StaticClass<class AHeroCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OUE_Source_OUE_Hero_Character_HeroCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
