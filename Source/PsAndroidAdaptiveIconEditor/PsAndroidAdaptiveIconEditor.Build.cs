// Copyright 2018 Mail.Ru Group. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class PsAndroidAdaptiveIconEditor : ModuleRules
{
	public PsAndroidAdaptiveIconEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"UnrealEd"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"InputCore",
				"SlateCore",
				"PropertyEditor",
				"ExternalImagePicker",
				"DetailCustomizations",
				"SharedSettingsWidgets",
				"EditorStyle"
			});

		PublicIncludePaths.AddRange(
			new string[] {
				"Developer/SharedSettingsWidgets/Public/"
			});
	}
}
