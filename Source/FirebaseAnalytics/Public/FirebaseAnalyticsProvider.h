#pragma once
#include "Interfaces/IAnalyticsProvider.h"

namespace firebase
{
	class App;
}

class FFirebaseAnalyticsProvider : public IAnalyticsProvider
{ 
public:
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

private:
	::firebase::App* FirebaseApp{ nullptr };
};

