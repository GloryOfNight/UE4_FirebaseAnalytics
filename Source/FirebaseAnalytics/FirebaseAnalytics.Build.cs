// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class FirebaseAnalytics : ModuleRules
{
	public FirebaseAnalytics(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[]{"Core", "CoreUObject", "Engine" , "Analytics"});

		PublicIncludePaths.AddRange
		(
			new string[]
			{
				"$(ModuleDir)/Public",
				Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/include/"))
			}
		);

		string FirebaseSDK_LibPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/"));

		if (Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Win32)
		{
			string Arch = Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86";
			
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "windows", Arch,"firebase_app.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "windows", Arch, "firebase_analytics.lib"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "linux", "i386", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "linux", "i386", "libfirebase_analytics.a"));

			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "linux", "x86_64", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "linux", "x86_64", "libfirebase_analytics.a"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicDependencyModuleNames.AddRange(new string[] { "Launch", "ApplicationCore" });

			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "android", "armeabi-v7a", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "android", "armeabi-v7a", "libfirebase_analytics.a"));

			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "android", "arm64-v8a", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "android", "arm64-v8a", "libfirebase_analytics.a"));

			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "android", "x86", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "android", "x86", "libfirebase_analytics.a"));

			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "FirebaseAnalyticsAndroid_UPL.xml"));
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "ios", "armv7", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "ios", "armv7", "libfirebase_analytics.a"));

			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "ios", "arm64", "libfirebase_app.a"));
			PublicAdditionalLibraries.Add(Path.Combine(FirebaseSDK_LibPath, "ios", "arm64", "libfirebase_analytics.a"));
		}
	}
}
