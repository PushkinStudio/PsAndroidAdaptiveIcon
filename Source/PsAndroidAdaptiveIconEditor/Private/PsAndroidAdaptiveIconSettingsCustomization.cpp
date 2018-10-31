// Copyright 2015-2018 Mail.Ru Group. All Rights Reserved.

#include "PsAndroidAdaptiveIconEditorPCH.h"
#include "PsAndroidAdaptiveIconSettings.h"
#include "Misc/Paths.h"
#include "Misc/App.h"
#include "Layout/Margin.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "DetailCategoryBuilder.h"
#include "SExternalImageReference.h"

#define LOCTEXT_NAMESPACE "FPsAndroidAdaptiveIconSettings"

TSharedRef<IDetailCustomization> FPsAndroidAdaptiveIconSettingsCustomization::MakeInstance()
{
	return MakeShareable(new FPsAndroidAdaptiveIconSettingsCustomization);
}

void FPsAndroidAdaptiveIconSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	// Background
	const FText DescBG(LOCTEXT("AndroidAdaptiveIconBackgroundLabel", "Android adaptive icon background"));
	const FString ProjectIconBG_TargetImagePath = FPaths::ProjectDir() / TEXT("Intermediate") / TEXT("Android") / TEXT("AdaptiveIcon") / TEXT("background.png");
	FString ProjectIconBG_AutomaticImagePath = ProjectIconBG_TargetImagePath;
	if (!FPaths::FileExists(ProjectIconBG_AutomaticImagePath))
	{
		ProjectIconBG_AutomaticImagePath = FPaths::ProjectPluginsDir() / TEXT("PsAndroidAdaptiveIcon") / TEXT("Resources") / TEXT("Defaults") / TEXT("background.png");
	}
	AddIcon(DetailBuilder, DescBG, ProjectIconBG_TargetImagePath, ProjectIconBG_AutomaticImagePath);

	// Foreground
	const FText DescFG(LOCTEXT("AndroidAdaptiveIconForegroundLabel", "Android adaptive icon foreground"));
	const FString ProjectIconFG_TargetImagePath = FPaths::ProjectDir()  / TEXT("Intermediate") / TEXT("Android") / TEXT("AdaptiveIcon") / TEXT("foreground.png");
	FString ProjectIconFG_AutomaticImagePath = ProjectIconFG_TargetImagePath;
	if (!FPaths::FileExists(ProjectIconFG_AutomaticImagePath))
	{
		ProjectIconFG_AutomaticImagePath = FPaths::ProjectPluginsDir() / TEXT("PsAndroidAdaptiveIcon") / TEXT("Resources") / TEXT("Defaults") / TEXT("foreground.png");
	}
	AddIcon(DetailBuilder, DescFG, ProjectIconFG_TargetImagePath, ProjectIconFG_AutomaticImagePath);

	// Foreground round
	const FText DescFGR(LOCTEXT("AndroidAdaptiveIconForegroundRoundLabel", "Android adaptive icon foreground round"));
	const FString ProjectIconFGR_TargetImagePath = FPaths::ProjectDir()  / TEXT("Intermediate") / TEXT("Android") / TEXT("AdaptiveIcon") / TEXT("foreground_round.png");
	FString ProjectIconFGR_AutomaticImagePath = ProjectIconFGR_TargetImagePath;
	if (!FPaths::FileExists(ProjectIconFGR_AutomaticImagePath))
	{
		ProjectIconFGR_AutomaticImagePath = FPaths::ProjectPluginsDir() / TEXT("PsAndroidAdaptiveIcon") / TEXT("Resources") / TEXT("Defaults") / TEXT("foreground_round.png");
	}
	AddIcon(DetailBuilder, DescFGR, ProjectIconFGR_TargetImagePath, ProjectIconFGR_AutomaticImagePath);
}

void FPsAndroidAdaptiveIconSettingsCustomization::AddIcon(IDetailLayoutBuilder& DetailBuilder, const FText& Description, const FString& TargetPath, const FString& AutoPath)
{
	IDetailCategoryBuilder& ImageCategory = DetailBuilder.EditCategory(TEXT("Android"));
	ImageCategory.AddCustomRow(Description)
	.NameContent()
	[
		SNew(SHorizontalBox)
	 	+SHorizontalBox::Slot()
	 	.Padding( FMargin( 0, 1, 0, 1 ) )
	 	.FillWidth(1.0f)
	 	[
		 	SNew(STextBlock)
		 	.Text(Description)
		 	.Font(DetailBuilder.GetDetailFont())
		]
	]
	.ValueContent()
	.MaxDesiredWidth(500.0f)
	.MinDesiredWidth(100.0f)
	[
	 	SNew(SHorizontalBox)
	 	+SHorizontalBox::Slot()
	 	.FillWidth(1.0f)
	 	.VAlign(VAlign_Center)
	 	[
		 	SNew(SExternalImageReference, AutoPath, TargetPath)
		 	.FileDescription(Description)
		 	.RequiredSize(FIntPoint(108, 108))
		]
	];
}

#undef LOCTEXT_NAMESPACE
