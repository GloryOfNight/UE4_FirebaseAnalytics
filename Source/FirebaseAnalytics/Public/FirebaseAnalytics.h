// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "../Public/FirebaseAnalyticsProvider.h"
#include "Interfaces/IAnalyticsProviderModule.h"

class FFirebaseAnalytics : public IAnalyticsProviderModule
{
	/** Singleton for analytics */

	TSharedPtr<IAnalyticsProvider> FirebaseAnalyticsProvider;

	static inline FFirebaseAnalytics& Get()
	{
		return FModuleManager::LoadModuleChecked< FFirebaseAnalytics >("FirebaseAnalytics");
	}

	virtual TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
