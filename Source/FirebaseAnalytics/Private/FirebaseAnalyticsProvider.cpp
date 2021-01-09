#include "FirebaseAnalyticsProvider.h"

#include "firebase/analytics.h"
#include "firebase/analytics/event_names.h"
#include "firebase/analytics/parameter_names.h"
#include "firebase/analytics/user_property_names.h"
#include "firebase/app.h"

#include "Analytics.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#endif

FFirebaseAnalyticsProvider::FFirebaseAnalyticsProvider()
	: FirebaseApp{nullptr}
{
}

FFirebaseAnalyticsProvider::~FFirebaseAnalyticsProvider()
{
	EndSession();
}

bool FFirebaseAnalyticsProvider::StartSession(const TArray<FAnalyticsEventAttribute>& Attributes)
{
#if PLATFORM_ANDROID
	FirebaseApp = ::firebase::App::Create(::firebase::AppOptions(), FAndroidApplication::GetJavaEnv(), FJavaWrapper::GameActivityThis);
#elif PLATFORM_IOS
	FirebaseApp = ::firebase::App::Create(::firebase::AppOptions());
#else

	// Firebase support only Android & iOS platform and retrieve options from google_services.json
	// in order to create FirebaseApp for PC platform, we manualy creating Options and filling them
	::firebase::AppOptions Options;
	Options.set_api_key("Empty");
	Options.set_app_id("Empty");
	Options.set_database_url("Empty");
	Options.set_ga_tracking_id("Empty");
	Options.set_messaging_sender_id("Empty");
	Options.set_project_id("Empty");
	Options.set_storage_bucket("Empty");

	FirebaseApp = ::firebase::App::Create(Options);
#endif

	if (FirebaseApp)
	{
		::firebase::analytics::Initialize(*FirebaseApp);
		::firebase::analytics::SetAnalyticsCollectionEnabled(true);
		::firebase::analytics::SetSessionTimeoutDuration(1000 * 60 * 30);
	}

	return FirebaseApp != nullptr;
}

void FFirebaseAnalyticsProvider::RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes)
{
	if (FirebaseApp)
	{
		const int32 AttrNum{Attributes.Num()};
		if (AttrNum == 0)
		{
			::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName));
		}
		else if (AttrNum == 1)
		{
			const auto& Attr = Attributes[0];
			switch (Attr.AttrType)
			{
			case FAnalyticsEventAttribute::AttrTypeEnum::String:
				::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName), TCHAR_TO_UTF8(*Attr.AttrName), TCHAR_TO_UTF8(*Attr.AttrValueString));
				break;
			case FAnalyticsEventAttribute::AttrTypeEnum::Number:

				::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName), TCHAR_TO_UTF8(*Attr.AttrName), Attr.AttrValueNumber);
				break;
			case FAnalyticsEventAttribute::AttrTypeEnum::Boolean:
				::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName), TCHAR_TO_UTF8(*Attr.AttrName), Attr.AttrValueBool);
				break;
			case FAnalyticsEventAttribute::AttrTypeEnum::JsonFragment:
				::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName), TCHAR_TO_UTF8(*Attr.AttrName), TCHAR_TO_UTF8(*Attr.AttrValueString));
				break;
			case FAnalyticsEventAttribute::AttrTypeEnum::Null:
				::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName), TCHAR_TO_UTF8(*Attr.AttrName), TCHAR_TO_UTF8(*Attr.AttrValueString));
				break;
			default:
				ensure("unimplemented enum value!");
			}
		}
		else
		{
			std::vector<::firebase::analytics::Parameter> Parameters;
			AttributesToParameters(Attributes, Parameters);
			::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName), Parameters.data(), Parameters.size());
		}
	}
}

FString FFirebaseAnalyticsProvider::GetSessionID() const
{
	// No such thing in firebase, do nothing
	return "Unsupported";
}

bool FFirebaseAnalyticsProvider::SetSessionID(const FString& InSessionID)
{
	// No such thing in firebase, do nothing
	return false;
}

void FFirebaseAnalyticsProvider::FlushEvents()
{
	// No such thing in firebase, do nothing
	return;
}

void FFirebaseAnalyticsProvider::SetUserID(const FString& InUserID)
{
	if (FirebaseApp)
	{
		::firebase::analytics::SetUserId(TCHAR_TO_UTF8(*InUserID));
	}
}

FString FFirebaseAnalyticsProvider::GetUserID() const
{
	// You can set UserId to Firebase, but not retrieve. Its up to you handle this.
	return "Unsupported";
}

void FFirebaseAnalyticsProvider::AttributesToParameters(const TArray<FAnalyticsEventAttribute>& Attributes, std::vector<::firebase::analytics::Parameter>& Out)
{
	Out.reserve(Attributes.Num());
	for (const auto& Attr : Attributes)
	{
		switch (Attr.AttrType)
		{
		case FAnalyticsEventAttribute::AttrTypeEnum::String:
			Out.push_back({TCHAR_TO_UTF8(*Attr.AttrName), TCHAR_TO_UTF8(*Attr.AttrValueString)});
			break;
		case FAnalyticsEventAttribute::AttrTypeEnum::Number:
			Out.push_back({TCHAR_TO_UTF8(*Attr.AttrName), Attr.AttrValueNumber});
			break;
		case FAnalyticsEventAttribute::AttrTypeEnum::Boolean:
			Out.push_back({TCHAR_TO_UTF8(*Attr.AttrName), Attr.AttrValueBool});
			break;
		case FAnalyticsEventAttribute::AttrTypeEnum::JsonFragment:
			Out.push_back({TCHAR_TO_UTF8(*Attr.AttrName), TCHAR_TO_UTF8(*Attr.AttrValueString)});
			break;
		case FAnalyticsEventAttribute::AttrTypeEnum::Null:
			Out.push_back({TCHAR_TO_UTF8(*Attr.AttrName), TCHAR_TO_UTF8(*Attr.AttrValueString)});
			break;
		default:
			ensure("unimplemented enum value!");
		}
	}
}

void FFirebaseAnalyticsProvider::EndSession()
{
	if (FirebaseApp)
	{
		::firebase::analytics::Terminate();
		delete FirebaseApp;
		FirebaseApp = nullptr;
	}
}