#pragma once
#include "Interfaces/IAnalyticsProvider.h"
#include "../../ThirdParty/firebase_cpp_sdk/include/firebase/app.h"
#include "../../ThirdParty/firebase_cpp_sdk/include/firebase/analytics.h"
#include "../../ThirdParty/firebase_cpp_sdk/include/firebase/analytics/event_names.h"
#include "../../ThirdParty/firebase_cpp_sdk/include/firebase/analytics/parameter_names.h"
#include "../../ThirdParty/firebase_cpp_sdk/include/firebase/analytics/user_property_names.h"

class FFirebaseAnalyticsProvider : public IAnalyticsProvider
{
	
	 
public:
	bool FirebaseAnalyticsStarted = false;

	FFirebaseAnalyticsProvider();

	virtual bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;

	virtual void EndSession() override;

	virtual void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

	virtual FString GetSessionID() const override;

	virtual bool SetSessionID(const FString& InSessionID) override;

	virtual void FlushEvents() override;

	virtual void SetUserID(const FString& InUserID) override;

	virtual FString GetUserID() const override;

	~FFirebaseAnalyticsProvider();
};

