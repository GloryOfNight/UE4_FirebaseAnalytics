// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FirebaseAnalyticsModule.h"

#include "FirebaseAnalyticsProvider.h"

#define LOCTEXT_NAMESPACE "FFirebaseAnalyticsModule"

static TSharedPtr<IAnalyticsProvider> gProvider(nullptr);

FFirebaseAnalyticsModule::~FFirebaseAnalyticsModule()
{
	if (gProvider.IsValid())
	{
		// releases pointer so it will be properly deleted
		gProvider.Reset(); 
	}
}

TSharedPtr<IAnalyticsProvider> FFirebaseAnalyticsModule::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const
{
	if (GetConfigValue.IsBound())
	{
		if (!gProvider.IsValid())
		{
			gProvider = MakeShareable(new FFirebaseAnalyticsProvider());
		}
		return gProvider;
	}
	return gProvider;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFirebaseAnalyticsModule, FirebaseAnalytics)
