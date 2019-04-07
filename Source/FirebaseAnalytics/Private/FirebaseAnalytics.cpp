// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FirebaseAnalytics.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Interfaces/IAnalyticsProvider.h"
#include "../Public/FirebaseAnalyticsProvider.h"

#define LOCTEXT_NAMESPACE "FFirebaseAnalyticsModule"

void FFirebaseAnalytics::StartupModule()
{
	
}

void FFirebaseAnalytics::ShutdownModule()
{

}

TSharedPtr<IAnalyticsProvider> FFirebaseAnalytics::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate & GetConfigValue) const
{
	return GetConfigValue.IsBound() ?
		MakeShareable(new FFirebaseAnalyticsProvider()) : nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFirebaseAnalytics, FirebaseAnalytics)
