#pragma once
#include "Core.h"
#include "FirebaseAnalytics.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FirebaseAnalyticsBPLIb.generated.h"

UCLASS()
class FIREBASEANALYTICS_API UFirebaseAnalyticsBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static bool StartFirebaseSession();
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void EndFirebaseSession();

	/** Sets the user ID property. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseUserId(const FString ValueToSet);
	/** Set a user property to the given value. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseUserProperty(const FString Name, const FString Property);
	/* Sets the duration of inactivity that terminates the current session. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseTimeoutSessionDuration(const int32 Seconds);
	/** Sets whether analytics collection is enabled for this app on this device. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void SetFirebaseAnalyticsCollectionEnabled(const bool IsEnabled = true);
	/** Clears all analytics data for this app from the device and resets the app instance id.  */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Session")
		static void ResetFirebaseAnalyticsData();
	/** Sets the current screen name and screen class, which specifies the current visual context in your app. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void SetFirebaseCurrentScreen(FString ScreenName, FString ScreenClass);
	/** Log an event with no parameters. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseEvent(FString Name);
	/** Log an event with one string parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordEventWithStringParameter(FString Name, FString ParameterName, FString Parameter);
	/** Log an event with one float parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordEventWithFloatParameter(FString Name, FString ParameterName, float Parameter);
	/** Log an event with one 32-bit integer parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordEventWithIntParameter(FString Name, FString ParameterName, int32 Parameter);

	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseTutorialBegin();
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseTutorialEnd();
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseSpendVirtualCurrency(FString ItemName, FString CurrencyName, int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
		static void RecordFirebaseEventWithParameters(FString Category, TMap<FString, FString> ParamMap);
};