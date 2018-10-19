// Copyright 2018 Mail.Ru Group. All Rights Reserved.

#include "PsAndroidAdaptiveIconEditorPCH.h"
#include "PsAndroidAdaptiveIconEditor.h"
#include "PsAndroidAdaptiveIconSettings.h"
#include "PsAndroidAdaptiveIconSettingsCustomization.h"
#include "UObject/UObjectGlobals.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "EngineMinimal.h"
#include "DetailCustomizations.h"
#include "PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "PsAndroidAdaptive"

void FPsAndroidAdaptiveIconEditor::StartupModule()
{
	RegisterCustomClassLayout(UPsAndroidAdaptiveIconSettings::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FPsAndroidAdaptiveIconSettingsCustomization::MakeInstance));

	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Platforms", "AndroidAdaptiveIcon",
				LOCTEXT("RuntimeSettingsName", "AndroidAdaptiveIcon"),
				LOCTEXT("RuntimeSettingsDescription", "Project settings for Android adaptive icon"),
				GetMutableDefault<UPsAndroidAdaptiveIconSettings>());
	}
}

void FPsAndroidAdaptiveIconEditor::ShutdownModule()
{
}

void FPsAndroidAdaptiveIconEditor::RegisterCustomClassLayout(FName ClassName, FOnGetDetailCustomizationInstance DetailLayoutDelegate )
{
	check(ClassName != NAME_None);

	static FName PropertyEditor("PropertyEditor");
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(PropertyEditor);
	PropertyModule.RegisterCustomClassLayout(ClassName, DetailLayoutDelegate);
}

IMPLEMENT_MODULE(FPsAndroidAdaptiveIconEditor, PsAndroidAdaptiveIconEditor)

#undef LOCTEXT_NAMESPACE
