#include "../Public/FirebaseAnalyticsProvider.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#endif

::firebase::App* g_firebaseApp = nullptr;

FFirebaseAnalyticsProvider::FFirebaseAnalyticsProvider()
{

}

bool FFirebaseAnalyticsProvider::StartSession(const TArray<FAnalyticsEventAttribute>& Attributes)
{
	if (!FirebaseAnalyticsStarted)
	{
#if PLATFORM_ANDROID
		g_firebaseApp = ::firebase::App::Create(::firebase::AppOptions(), FAndroidApplication::GetJavaEnv(), FJavaWrapper::GameActivityThis);
#elif PLATFORM_IOS
		g_firebaseApp = ::firebase::App::Create(::firebase::AppOptions());
#else
		UE_LOG(LogTemp, Warning, TEXT("Firebase analytics cannot start on this platform"));
#endif

		if (g_firebaseApp)
		{
			::firebase::analytics::Initialize(*g_firebaseApp);
			return true;
		}
	}
	return false;
}

void FFirebaseAnalyticsProvider::RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) 
{
	::firebase::analytics::LogEvent(TCHAR_TO_UTF8(*EventName));
}

FString FFirebaseAnalyticsProvider::GetSessionID() const
{
	// Do nothing
	return FString();
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
	return "Cannon get UserID from this provider";
}

void FFirebaseAnalyticsProvider::EndSession()
{
	if (FirebaseAnalyticsStarted) 
	{
		::firebase::analytics::Terminate();
		FirebaseAnalyticsStarted = false;
	}
	
}

FFirebaseAnalyticsProvider::~FFirebaseAnalyticsProvider()
{
	delete g_firebaseApp;
	g_firebaseApp = nullptr;
}
