#pragma once
#include <vector>

#include "Containers/UnrealString.h"
#include "Interfaces/IAnalyticsProvider.h"

namespace firebase
{
	class App;
	namespace analytics
	{
		struct Parameter;
	}
} // namespace firebase

class FFirebaseAnalyticsProvider : public IAnalyticsProvider
{
public:
	FFirebaseAnalyticsProvider();
	virtual ~FFirebaseAnalyticsProvider();

	bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;

	void EndSession() override;

	void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

	FString GetSessionID() const override;

	bool SetSessionID(const FString& InSessionID) override;

	void FlushEvents() override;

	void SetUserID(const FString& InUserID) override;

	FString GetUserID() const override;

protected:
	void AttributesToParameters(const TArray<FAnalyticsEventAttribute>& Attributes, std::vector<::firebase::analytics::Parameter>& Out);

private:
	::firebase::App* FirebaseApp;
};
