// Copyright 2018 Mail.Ru Group. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class PsAndroidAdaptiveIcon : ModuleRules
{
	public PsAndroidAdaptiveIcon(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine"
			});

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "PsAndroidAdaptiveIcon_APL.xml"));
		}
	}
}
