// Copyright 2018 Mail.Ru Group. All Rights Reserved.
#pragma once

#include "Modules/ModuleManager.h"

class FPsAndroidAdaptiveIcon : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
	// End of IModuleInterface impl
};
