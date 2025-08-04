// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Proj_CookingMulti : ModuleRules
{
	public Proj_CookingMulti(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"SlateCore",
			"Paper2D"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Proj_CookingMulti",
			"Proj_CookingMulti/Variant_Platforming",
			"Proj_CookingMulti/Variant_Combat",
			"Proj_CookingMulti/Variant_Combat/AI",
			"Proj_CookingMulti/Variant_SideScrolling",
			"Proj_CookingMulti/Variant_SideScrolling/Gameplay",
			"Proj_CookingMulti/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
