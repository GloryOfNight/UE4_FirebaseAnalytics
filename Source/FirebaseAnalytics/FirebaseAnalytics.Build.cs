// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class FirebaseAnalytics : ModuleRules
{
	public FirebaseAnalytics(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[]{"Core", "CoreUObject", "Engine" , "Analytics"});
		
		PublicIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/include/")));
		
		if (Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Win32)
		{
			string Arch = Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86";
			
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/windows/", Arch,"firebase_app.lib")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/windows/", Arch, "firebase_analytics.lib")));
		}
		else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/linux/", "i386", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/linux/", "i386", "libfirebase_analytics.a")));

			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/linux/", "x86_64", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/linux/", "x86_64", "libfirebase_analytics.a")));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicDependencyModuleNames.AddRange(new string[] { "Launch", "ApplicationCore" });

			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/android/", "armeabi-v7a", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/android/", "armeabi-v7a", "libfirebase_analytics.a")));

			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/android/", "arm64-v8a", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/android/", "arm64-v8a", "libfirebase_analytics.a")));

			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/android/", "x86", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/android/", "x86", "libfirebase_analytics.a")));

			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "FirebaseAnalyticsAndroid_UPL.xml"));
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/ios/", "armv7", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/ios/", "armv7", "libfirebase_analytics.a")));

			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/ios/", "arm64", "libfirebase_app.a")));
			PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/ios/", "arm64", "libfirebase_analytics.a")));
		}
	}
}
