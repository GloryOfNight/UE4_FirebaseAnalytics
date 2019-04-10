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
	if (CanLogEvents()) 
	{
		::firebase::analytics::SetUserId(TCHAR_TO_UTF8(*ValueToSet));
	}
}

void UFirebaseAnalyticsBPLib::SetFirebaseUserProperty(const FString Name, const FString Property)
{
	if (CanLogEvents())
	{
		::firebase::analytics::SetUserProperty(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Property));
	}
}

void UFirebaseAnalyticsBPLib::SetFirebaseMinimumSessionDuration(const int32 Seconds)
{
	if (CanLogEvents()) 
	{
		::firebase::analytics::SetMinimumSessionDuration(static_cast<int64_t>(Seconds * 1000));
	}
}

void UFirebaseAnalyticsBPLib::SetFirebaseTimeoutSessionDuration(const int32 Seconds)
{
	if (CanLogEvents())
	{
		::firebase::analytics::SetSessionTimeoutDuration(static_cast<int64_t>(Seconds * 1000));
	}
}

void UFirebaseAnalyticsBPLib::SetAnalyticsCollectionEnabled(const bool IsEnabled)
{
	if (CanLogEvents())
	{
		::firebase::analytics::SetAnalyticsCollectionEnabled(IsEnabled);
	}
}

void UFirebaseAnalyticsBPLib::ResetFirebaseAnalyticsData()
{
	if (CanLogEvents())
	{
		::firebase::analytics::ResetAnalyticsData();
	}
}

void UFirebaseAnalyticsBPLib::SetFirebaseCurrentScreen(FString ScreenName, FString ScreenClass)
{
	if (CanLogEvents())
	{
		::firebase::analytics::SetCurrentScreen(TCHAR_TO_UTF8(*ScreenName), TCHAR_TO_UTF8(*ScreenClass));
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseEvent(FString Name)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name));
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseEventWithParamName(FString Name, FString ParameterName, FString Value)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), TCHAR_TO_UTF8(*Value));
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseEventWithFloatValue(FString Name, FString ParameterName, float Value)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseEventWithIntValue(FString Name, FString ParameterName, int32 Value)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*ParameterName), Value);
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseTutorialBegin(FString Name)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(::firebase::analytics::kEventTutorialBegin);
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseTutorialEnd(FString Name)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(::firebase::analytics::kEventTutorialComplete);
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseUnlockAchievement(FString AchievementID, int32 Value)
{
	if (CanLogEvents())
	{
		::firebase::analytics::LogEvent(::firebase::analytics::kEventUnlockAchievement, TCHAR_TO_UTF8(*AchievementID), Value);
	}
}

void UFirebaseAnalyticsBPLib::RecordFirebaseSpendVirtualCurrency(FString ItemName, FString CurrencyName, int32 Value)
{
	if (CanLogEvents()) 
	{
		using namespace ::firebase::analytics;

		const firebase::analytics::Parameter kSelectContentParameters[] = {
		Parameter(kParameterItemName, TCHAR_TO_UTF8(*ItemName)),
		Parameter(kParameterVirtualCurrencyName, TCHAR_TO_UTF8(*CurrencyName)),
		Parameter(kParameterValue, Value)
		};

		LogEvent(kEventSelectContent, kSelectContentParameters, 2);
	}
}

bool UFirebaseAnalyticsBPLib::CanLogEvents() 
{
	const auto provider = static_cast<FFirebaseAnalyticsProvider*>(FAnalytics::Get().GetDefaultConfiguredProvider().Get());

	return provider && ::firebase::App::GetInstance();
}