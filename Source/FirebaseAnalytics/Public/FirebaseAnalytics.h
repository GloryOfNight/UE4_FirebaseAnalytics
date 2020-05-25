// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "Interfaces/IAnalyticsProviderModule.h"

class FFirebaseAnalytics : public IAnalyticsProviderModule
{
public:
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;

	/** Singleton for analytics */
	TSharedPtr<IAnalyticsProvider> FirebaseAnalyticsProvider;

private:
	static inline FFirebaseAnalytics& Get();

	virtual TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;
};
