// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class FirebaseAnalytics : ModuleRules
{
	public FirebaseAnalytics(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {Path.Combine(ModuleDirectory, "../ThirdParty/FirebaseCpp/include")});

		PublicDependencyModuleNames.AddRange(new string[]{ "Core" });
			
		PrivateDependencyModuleNames.AddRange(new string[]{ "CoreUObject", "Engine", "Analytics" });


        if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/windows")));

            PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/windows/x64/firebase_analytics.lib")));
            PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/windows/x64/firebase_app.lib")));
        }

        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PublicDependencyModuleNames.AddRange(new string[] { "Launch" });

           // PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/armeabi")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/armeabi-v7a")));
          //  PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/arm64-v8a")));
           
            //PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/armeabi-v7a/c++/libfirebase_analytics.a")));
           // PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/armeabi-v7a/c++/libfirebase_app.a")));


            PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/armeabi-v7a/gnustl/libfirebase_analytics.a")));
            PublicAdditionalLibraries.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/FireBaseCpp/libs/android/armeabi-v7a/gnustl/libfirebase_app.a")));

            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "FirebaseAnalytics_UPL.xml"));
        }
    }
}
