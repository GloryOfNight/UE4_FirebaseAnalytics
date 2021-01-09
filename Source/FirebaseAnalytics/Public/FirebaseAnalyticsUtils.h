#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FirebaseAnalyticsUtils.generated.h"

UCLASS()
class FIREBASEANALYTICS_API UFirebaseAnalyticsUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Set a user property to the given value. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
	static void SetFirebaseUserProperty(const FString& Name, const FString& Property);

	/** Sets the duration of inactivity that terminates the current session. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
	static void SetFirebaseTimeoutSessionDuration(const int32 Seconds);

	/** Sets whether analytics collection is enabled for this app on this device. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
	static void SetFirebaseAnalyticsCollectionEnabled(const bool IsEnabled = true);

	/** Clears all analytics data for this app from the device and resets the app instance id.  */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
	static void ResetFirebaseAnalyticsData();

	/** Sets the current screen name and screen class, which specifies the current visual context in your app. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics")
	static void SetFirebaseCurrentScreen(const FString& ScreenName, const FString& ScreenClass);

	/** Log an event with no parameters. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebaseEvent(const FString& Name);

	/** Log an event with one string parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordEventWithStringParameter(const FString& Name, const FString& ParameterName, const FString& Value);

	/** Log an event with one float parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordEventWithFloatParameter(const FString& Name, const FString& ParameterName, const float Value);

	/** Log an event with one 32-bit integer parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordEventWithInt32Parameter(const FString& Name, const FString& ParameterName, const int32 Value);

	/** Log an event with one 64-bit integer parameter. */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordEventWithInt64Parameter(const FString& Name, const FString& ParameterName, const int64 Value);

	/** Log an tutorial begin event */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebaseTutorialBegin();

	/** Log an tutorial end event */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebaseTutorialEnd();

	/** Log an level end event */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebaseLevelEnd(const FString& LevelName, const FString& Success);

	/** Log an level start event */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebaseLevelStart(const FString& LevelName);

	/** Log an level up event */
	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebaseLevelUp();

	UFUNCTION(BlueprintCallable, Category = "Firebase | Analytics | Events")
	static void RecordFirebasePurchase(const FString& Affiliation, const FString& Coupon, const FString& Currency, const TArray<FString>& Items, const float Shipping, const float Tax, const FString& TransactionID, const float Value);

	static void RecordFirebasePurchase(const FString& Affiliation, const FString& Coupon, const FString& Currency, const TArray<FString>& Items, const double Shipping, const double Tax, const FString& TransactionID, const double Value);
};