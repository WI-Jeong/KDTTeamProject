// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OUEGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OUE_OUEGameMode_generated_h
#error "OUEGameMode.generated.h already included, missing '#pragma once' in OUEGameMode.h"
#endif
#define OUE_OUEGameMode_generated_h

#define FID_OUE_Source_OUE_OUEGameMode_h_12_SPARSE_DATA
#define FID_OUE_Source_OUE_OUEGameMode_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_OUE_Source_OUE_OUEGameMode_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_OUE_Source_OUE_OUEGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_OUE_Source_OUE_OUEGameMode_h_12_ACCESSORS
#define FID_OUE_Source_OUE_OUEGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOUEGameMode(); \
	friend struct Z_Construct_UClass_AOUEGameMode_Statics; \
public: \
	DECLARE_CLASS(AOUEGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/OUE"), OUE_API) \
	DECLARE_SERIALIZER(AOUEGameMode)


#define FID_OUE_Source_OUE_OUEGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OUE_API AOUEGameMode(AOUEGameMode&&); \
	OUE_API AOUEGameMode(const AOUEGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OUE_API, AOUEGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOUEGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOUEGameMode) \
	OUE_API virtual ~AOUEGameMode();


#define FID_OUE_Source_OUE_OUEGameMode_h_9_PROLOG
#define FID_OUE_Source_OUE_OUEGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OUE_Source_OUE_OUEGameMode_h_12_SPARSE_DATA \
	FID_OUE_Source_OUE_OUEGameMode_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_OUE_Source_OUE_OUEGameMode_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_OUE_Source_OUE_OUEGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OUE_Source_OUE_OUEGameMode_h_12_ACCESSORS \
	FID_OUE_Source_OUE_OUEGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_OUE_Source_OUE_OUEGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OUE_API UClass* StaticClass<class AOUEGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OUE_Source_OUE_OUEGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
