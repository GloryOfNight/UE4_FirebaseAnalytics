#include "../Public/FirebaseAnalyticsBPLib.h"
#include "../Public/FirebaseAnalyticsProvider.h"
#include "Runtime/Analytics/Analytics/Public/Analytics.h"
bool UFirebaseAnalyticsBPLib::StartFirebaseSession()
{
	return FAnalytics::Get().GetDefaultConfiguredProvider()->StartSession();
}

void UFirebaseAnalyticsBPLib::EndFirebaseSession()
{
	return FAnalytics::Get().GetDefaultConfiguredProvider()->EndSession();
}

void UFirebaseAnalyticsBPLib::SetFirebaseUserId(const FString ValueToSet)
{

	::firebase::analytics::SetUserId(TCHAR_TO_UTF8(*ValueToSet));
}

void UFirebaseAnalyticsBPLib::SetFirebaseUserProperty(const FString Name, const FString Property)
{
	::firebase::analytics::SetUserProperty(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Property));
}

void UFirebaseAnalyticsBPLib::SetFirebaseTimeoutSessionDuration(const int32 Seconds)
{
	::firebase::analytics::SetSessionTimeoutDuration(static_cast<int64_t>(Seconds * 1000));
}

void UFirebaseAnalyticsBPLib::SetFirebaseAnalyticsCollectionEnabled(const bool IsEnabled)
{
	::firebase::analytics::SetAnalyticsCollectionEnabled(IsEnabled);
}

void UFirebaseAnalyticsBPLib::ResetFirebaseAnalyticsData()
{
	::firebase::analytics::ResetAnalyticsData();
}

void UFirebaseAnalyticsBPLib::SetFirebaseCurrentScreen(FString ScreenName, FString ScreenClass)
{
	::firebase::analytics::SetCurrentScreen(TCHAR_TO_UTF8(*ScreenName), TCHAR_TO_UTF8(*ScreenClass));
}

void UFirebaseAnalyticsBPLib::RecordFirebaseEvent(FString Name)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name));
}

void UFirebaseAnalyticsBPLib::RecordEventWithStringParameter(FString Name, FString ParameterName, FString Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), TCHAR_TO_UTF8(*Value));
}

void UFirebaseAnalyticsBPLib::RecordEventWithFloatParameter(FString Name, FString ParameterName, float Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
}

void UFirebaseAnalyticsBPLib::RecordEventWithIntParameter(FString Name, FString ParameterName, int32 Value)
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
}

void UFirebaseAnalyticsBPLib::RecordFirebaseTutorialBegin()
{
	::firebase::analytics::LogEvent(::firebase::analytics::kEventTutorialBegin);
}

void UFirebaseAnalyticsBPLib::RecordFirebaseTutorialEnd()
{
	::firebase::analytics::LogEvent(::firebase::analytics::kEventTutorialComplete);
}

void UFirebaseAnalyticsBPLib::RecordFirebaseSpendVirtualCurrency(FString ItemName, FString CurrencyName, int32 Value)
{
	using namespace ::firebase::analytics;

	const Parameter kParameters[] = 
	{
	Parameter(kParameterItemName, TCHAR_TO_UTF8(*ItemName)),
	Parameter(kParameterVirtualCurrencyName, TCHAR_TO_UTF8(*CurrencyName)),
	Parameter(kParameterValue, Value)
	};

	LogEvent(kEventSelectContent, kParameters, sizeof(kParameters) / sizeof(kParameters[0]));
}

void UFirebaseAnalyticsBPLib::RecordFirebaseEventWithParameters(FString Category, TMap<FString, FString> Params) 
{
	using namespace ::firebase::analytics;

	const int32 TotalParams = Params.Num();
	if (TotalParams > 0) 
	{
		Parameter* kParameters = new Parameter[TotalParams];

		int32 counter = 0;
		for (const auto& i : Params) 
		{
			kParameters[counter] = Parameter(TCHAR_TO_UTF8(*i.Key), TCHAR_TO_UTF8(*i.Value));
			++counter;
		}

		LogEvent(TCHAR_TO_UTF8(*Category), kParameters, static_cast<size_t>(TotalParams));

		delete[] kParameters;
	}
}
