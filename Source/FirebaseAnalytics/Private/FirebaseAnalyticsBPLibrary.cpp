// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FirebaseAnalyticsBPLibrary.h"
#include "FirebaseAnalytics.h"

#include "../../ThirdParty/FirebaseCpp/include/firebase/app.h"
#include "../../ThirdParty/FirebaseCpp/include/firebase/analytics.h"
#include "../../ThirdParty/FirebaseCpp/include/firebase/analytics/event_names.h"
#include "../../ThirdParty/FirebaseCpp/include/firebase/analytics/parameter_names.h"
#include "../../ThirdParty/FirebaseCpp/include/firebase/analytics/user_property_names.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

UFirebaseAnalyticsBPLibrary::UFirebaseAnalyticsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


void UFirebaseAnalyticsBPLibrary::CreateAndTestFirebase() 
{
	firebase::AppOptions Options;

	Options.set_api_key("AIzaSyAyd7iQTiO4yuR4lL-A9HFYpkIZZ6UGxe4");
	Options.set_app_id("1:149300916034:android:8485a5e9f25f7d59");
	Options.set_project_id("bombanino-3327b");
	Options.set_ga_tracking_id("bombanino-3327b");

	firebase::App* app;

#if PLATFORM_ANDROID
	app = firebase::App::Create(Options, FAndroidApplication::GetJavaEnv(), FJavaWrapper::GameActivityThis);
#else
	app = firebase::App::Create(Options);
#endif

	firebase::analytics::Initialize(*app);
	firebase::analytics::LogEvent(firebase::analytics::kEventPostScore, firebase::analytics::kParameterScore, 42);
}
