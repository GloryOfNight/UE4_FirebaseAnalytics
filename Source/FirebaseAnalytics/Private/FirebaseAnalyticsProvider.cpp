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
	if (!FirebaseAnalyticsStarted)
	{
#if PLATFORM_ANDROID
		firebaseAnalyticsApp = ::firebase::App::Create(::firebase::AppOptions(), FAndroidApplication::GetJavaEnv(), FJavaWrapper::GameActivityThis);
#elif PLATFORM_IOS
		firebaseAnalyticsApp = ::firebase::App::Create(::firebase::AppOptions());
#else
		UE_LOG(LogTemp, Warning, TEXT("Firebase analytics cannot start on this platform"));
#endif

		if (firebaseAnalyticsApp)
		{
			::firebase::analytics::Initialize(*firebaseAnalyticsApp);
			FirebaseAnalyticsStarted = true;
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
	if (FirebaseAnalyticsStarted) 
	{
		::firebase::analytics::Terminate();
		FirebaseAnalyticsStarted = false;
	}
}

FFirebaseAnalyticsProvider::~FFirebaseAnalyticsProvider()
{
	EndSession();
}
