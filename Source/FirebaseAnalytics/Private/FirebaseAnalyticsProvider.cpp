#include "../Public/FirebaseAnalyticsProvider.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#endif

FFirebaseAnalyticsProvider::FFirebaseAnalyticsProvider()
{

}

bool FFirebaseAnalyticsProvider::StartSession(const TArray<FAnalyticsEventAttribute>& Attributes)
{
	if (!firebase::App::GetInstance())
	{
		::firebase::App* firebaseAnalyticsApp = nullptr;

#if PLATFORM_ANDROID
		firebaseAnalyticsApp = ::firebase::App::Create(::firebase::AppOptions(), FAndroidApplication::GetJavaEnv(), FJavaWrapper::GameActivityThis);
#elif PLATFORM_IOS
		firebaseAnalyticsApp = ::firebase::App::Create(::firebase::AppOptions());
#else
		// Firebase support only Android & iOS platform,
		// but in need make debug easier we creating fake options so firebase can create an app
		::firebase::AppOptions Options;
		Options.set_api_key("Empty");
		Options.set_app_id("Empty");
		Options.set_database_url("Empty");
		Options.set_ga_tracking_id("Empty");
		Options.set_messaging_sender_id("Empty");
		Options.set_project_id("Empty");
		Options.set_storage_bucket("Empty");

		firebaseAnalyticsApp = ::firebase::App::Create(Options);
#endif
		if (firebaseAnalyticsApp)
		{
			::firebase::analytics::Initialize(*firebaseAnalyticsApp);
			return true;
		}
	}
	return false;
}

void FFirebaseAnalyticsProvider::RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) 
{
	if (::firebase::App::GetInstance()) 
	{
		::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName));
	}
}

FString FFirebaseAnalyticsProvider::GetSessionID() const
{
	// Do nothing
	return "Unsupported";
}

bool FFirebaseAnalyticsProvider::SetSessionID(const FString & InSessionID)
{
	// Do nothing
	return false;
}

void FFirebaseAnalyticsProvider::FlushEvents()
{
	// Do nothing
	return;
}

void FFirebaseAnalyticsProvider::SetUserID(const FString & InUserID)
{
	::firebase::analytics::SetUserId(TCHAR_TO_UTF8(*InUserID));
}

FString FFirebaseAnalyticsProvider::GetUserID() const
{
	// Do nothing
	return "Unsupported";
}

void FFirebaseAnalyticsProvider::EndSession()
{
	if (::firebase::App::GetInstance())
	{
		::firebase::analytics::Terminate();
		firebase::App::GetInstance()->~App();
	}
}

FFirebaseAnalyticsProvider::~FFirebaseAnalyticsProvider()
{
	
}
