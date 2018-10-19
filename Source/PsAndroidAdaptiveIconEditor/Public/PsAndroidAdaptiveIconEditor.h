// Copyright 2018 Mail.Ru Group. All Rights Reserved.
#pragma once

#include "Modules/ModuleManager.h"
#include "PropertyEditorDelegates.h"

class FPsAndroidAdaptiveIconEditor : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
	// End of IModuleInterface impl

private:
	void RegisterCustomClassLayout(FName ClassName, FOnGetDetailCustomizationInstance DetailLayoutDelegate );

	UPROPERTY()
	class UPsAndroidAdaptiveIconSettings* Settings;
};
