#pragma once
#include "Core.h"
#include "FirebaseAnalytics.h"
#include "FirebaseAnalyticsBPLIb.generated.h"

UCLASS()
class FIREBASEANALYTICS_API UFirebaseAnalyticsBPLib : public UObject 
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static bool StartFirebaseSession();
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void EndFirebaseSession();

	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseUserId(const FString ValueToSet);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseUserProperty(const FString Name, const FString Property);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseMinimumSessionDuration(const int32 Seconds);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseTimeoutSessionDuration(const int32 Seconds);
	/** Sets whether analytics collection is enabled for this app on this device. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
		static void SetAnalyticsCollectionEnabled(const bool IsEnabled = true);
	/** Clears all analytics data for this app from the device and resets the app instance id.  */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
		static void ResetFirebaseAnalyticsData();

	/** Sets the current screen name and screen class, which specifies the current visual context in your app. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
		static void SetFirebaseCurrentScreen(const FString ScreenName, const FString ScreenClass);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseEvent(FString Name);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseEventWithParamName(FString Name, FString ParameterName);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseEventWithFloatValue(FString Name, FString ParameterName, float Value);
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseEventWithIntValue(FString Name, FString ParameterName, int32 Value);

	static FFirebaseAnalyticsProvider* GetFirebaseProvider();
};