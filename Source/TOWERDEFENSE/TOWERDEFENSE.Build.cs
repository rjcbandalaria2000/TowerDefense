// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TOWERDEFENSE : ModuleRules
{
	public TOWERDEFENSE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
