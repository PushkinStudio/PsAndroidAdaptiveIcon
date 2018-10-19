// Copyright 2018 Mail.Ru Group. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FPsAndroidAdaptiveIconSettingsCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	
	void CustomizeDetails(class IDetailLayoutBuilder& DetailBuilder) override;

private:
	void AddIcon(class IDetailLayoutBuilder& DetailBuilder, const FText& Description, const FString& TargetPath, const FString& AutoPath);
};
