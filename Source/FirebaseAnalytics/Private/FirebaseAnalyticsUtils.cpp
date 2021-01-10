#include "FirebaseAnalyticsUtils.h"

#include "firebase/analytics.h"
#include "firebase/analytics/event_names.h"
#include "firebase/analytics/parameter_names.h"

#include "Analytics.h"
#include "FirebaseAnalyticsProvider.h"

void UFirebaseAnalyticsUtils::SetFirebaseUserProperty(const FString& Name, const FString& Property)
{
	::firebase::analytics::SetUserProperty(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Property));
}

void UFirebaseAnalyticsUtils::SetFirebaseTimeoutSessionDuration(const int32 Seconds)
{
	::firebase::analytics::SetSessionTimeoutDuration(static_cast<int64_t>(Seconds * 1000));
}

void UFirebaseAnalyticsUtils::SetFirebaseAnalyticsCollectionEnabled(const bool IsEnabled)
{
	::firebase::analytics::SetAnalyticsCollectionEnabled(IsEnabled);
}

void UFirebaseAnalyticsUtils::ResetFirebaseAnalyticsData()
{
	::firebase::analytics::ResetAnalyticsData();
}

void UFirebaseAnalyticsUtils::SetFirebaseCurrentScreen(const FString& ScreenName, const FString& ScreenClass)
{
	::firebase::analytics::SetCurrentScreen(TCHAR_TO_UTF8(*ScreenName), TCHAR_TO_UTF8(*ScreenClass));
}

void UFirebaseAnalyticsUtils::RecordFirebaseEvent(const FString& Name)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name));
}

void UFirebaseAnalyticsUtils::RecordEventWithStringParameter(const FString& Name, const FString& ParameterName, const FString& Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), TCHAR_TO_UTF8(*Value));
}

void UFirebaseAnalyticsUtils::RecordEventWithFloatParameter(const FString& Name, const FString& ParameterName, const float Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
}

void UFirebaseAnalyticsUtils::RecordEventWithInt32Parameter(const FString& Name, const FString& ParameterName, const int32 Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
}

void UFirebaseAnalyticsUtils::RecordEventWithInt64Parameter(const FString& Name, const FString& ParameterName, const int64 Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
}

void UFirebaseAnalyticsUtils::RecordFirebaseTutorialBegin()
{
	::firebase::analytics::LogEvent(::firebase::analytics::kEventTutorialBegin);
}

void UFirebaseAnalyticsUtils::RecordFirebaseTutorialEnd()
{
	::firebase::analytics::LogEvent(::firebase::analytics::kEventTutorialComplete);
}

void UFirebaseAnalyticsUtils::RecordFirebaseLevelEnd(const FString& LevelName, const FString& Success)
{
	// clang-format off
	std::vector<::firebase::analytics::Parameter> Parameters = 
	{
		{::firebase::analytics::kParameterLevelName, TCHAR_TO_UTF8(*LevelName)}, 
		{::firebase::analytics::kParameterSuccess, TCHAR_TO_UTF8(*Success)}
	};
	// clang-format on
	::firebase::analytics::LogEvent(::firebase::analytics::kEventLevelEnd, Parameters.data(), Parameters.size());
}

void UFirebaseAnalyticsUtils::RecordFirebaseLevelStart(const FString& LevelName)
{
	::firebase::analytics::LogEvent(::firebase::analytics::kEventLevelStart, ::firebase::analytics::kParameterLevelName, TCHAR_TO_UTF8(*LevelName));
}

void UFirebaseAnalyticsUtils::RecordFirebaseLevelUp()
{
	::firebase::analytics::LogEvent(::firebase::analytics::kEventLevelUp);
}

void UFirebaseAnalyticsUtils::RecordFirebasePurchase(const FString& Affiliation, const FString& Coupon, const FString& Currency, const TArray<FString>& Items, const float Shipping, const float Tax, const FString& TransactionID, const float Value)
{
	RecordFirebasePurchase(Affiliation, Coupon, Currency, Items, static_cast<double>(Shipping), static_cast<double>(Tax), TransactionID, static_cast<double>(Value));
}

void UFirebaseAnalyticsUtils::RecordFirebasePurchase(const FString& Affiliation, const FString& Coupon, const FString& Currency, const TArray<FString>& Items, const double Shipping, const double Tax, const FString& TransactionID, const double Value)
{
	std::vector<std::string> ItemsVec;
	ItemsVec.reserve(Items.Num());
	for (const auto& Item : Items)
	{
		ItemsVec.push_back(TCHAR_TO_UTF8(*Item));
	}

	// clang-format off
	std::vector<::firebase::analytics::Parameter> Parameters = 
	{
		{::firebase::analytics::kParameterAffiliation, TCHAR_TO_UTF8(*Affiliation)}, 
		{::firebase::analytics::kParameterCoupon, TCHAR_TO_UTF8(*Coupon)},
		{::firebase::analytics::kParameterCurrency, TCHAR_TO_UTF8(*Currency)},
		{"items", ItemsVec},
		{::firebase::analytics::kParameterShipping, Shipping},
		{::firebase::analytics::kParameterTax, Tax},
		{::firebase::analytics::kParameterTransactionID, TCHAR_TO_UTF8(*TransactionID)},
		{::firebase::analytics::kParameterValue, Value},
	};
	// clang-format on
	::firebase::analytics::LogEvent(::firebase::analytics::kEventLevelEnd, Parameters.data(), Parameters.size());
}
