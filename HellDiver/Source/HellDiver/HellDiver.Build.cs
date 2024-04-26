// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HellDiver : ModuleRules
{
	public HellDiver(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

        PublicIncludePaths.Add("HellDiver");
    }
}
