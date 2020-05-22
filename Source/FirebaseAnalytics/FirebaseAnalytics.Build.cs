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
            string PlatformName = Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86";

            PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/windows/", PlatformName,"firebase_app.lib")));
            PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/firebase_cpp_sdk/libs/windows/", PlatformName, "firebase_analytics.lib")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            string linuxlibpath = "../ThirdParty/firebase_cpp_sdk/libs/linux/";

            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, linuxlibpath + "i386"));
            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, linuxlibpath + "x86_64"));

            PublicAdditionalLibraries.Add("firebase_app");
            PublicAdditionalLibraries.Add("firebase_analytics");
        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PublicDependencyModuleNames.AddRange(new string[] { "Launch", "ApplicationCore" });

            string androidlibpath = "../ThirdParty/firebase_cpp_sdk/libs/android/";

            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, androidlibpath + "armeabi-v7a"));
            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, androidlibpath + "arm64-v8a"));
            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, androidlibpath + "x86"));

            PublicAdditionalLibraries.Add("firebase_app");
            PublicAdditionalLibraries.Add("firebase_analytics");

            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "FirebaseAnalyticsAndroid_UPL.xml"));
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            string ioslibpath = "../ThirdParty/firebase_cpp_sdk/libs/ios/";

            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, ioslibpath + "armv7"));
            PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, ioslibpath + "arm64"));

            PublicAdditionalLibraries.Add("firebase_app");
            PublicAdditionalLibraries.Add("firebase_analytics");
        }
    }
}
