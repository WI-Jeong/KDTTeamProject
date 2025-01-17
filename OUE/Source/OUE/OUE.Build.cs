// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OUE : ModuleRules
{
	public OUE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","UMG", "Niagara", "AIModule", "CinematicCamera" });

        PublicIncludePaths.Add("OUE");
    }
}
