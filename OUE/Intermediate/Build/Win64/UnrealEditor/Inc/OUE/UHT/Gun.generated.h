// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Hero/Gun/Gun.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OUE_Gun_generated_h
#error "Gun.generated.h already included, missing '#pragma once' in Gun.h"
#endif
#define OUE_Gun_generated_h

#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGunDataTableRow_Statics; \
	OUE_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> OUE_API UScriptStruct* StaticStruct<struct FGunDataTableRow>();

#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_SPARSE_DATA
#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_ACCESSORS
#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGun(); \
	friend struct Z_Construct_UClass_AGun_Statics; \
public: \
	DECLARE_CLASS(AGun, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OUE"), NO_API) \
	DECLARE_SERIALIZER(AGun)


#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGun(AGun&&); \
	NO_API AGun(const AGun&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGun); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGun); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGun) \
	NO_API virtual ~AGun();


#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_33_PROLOG
#define FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_SPARSE_DATA \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_ACCESSORS \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_INCLASS_NO_PURE_DECLS \
	FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OUE_API UClass* StaticClass<class AGun>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OUEProject_OUE_Source_OUE_Hero_Gun_Gun_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
