// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Interfaces/IAnalyticsProviderModule.h"
#include "Modules/ModuleManager.h"

class FFirebaseAnalyticsModule : public IAnalyticsProviderModule
{
public:
	virtual ~FFirebaseAnalyticsModule();
private:
	TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;
};
