# UE4_FirebaseAnalytics
Free open source Firebase analytics provider for Unreal Engine 4. 

# Imrpotant notes: 
Plugin currently support only Android target platfrom, iOS support still in develop.
Current supported engine version: 4.21.3 (master branch)

# Features
1. Android multiple CPU architecture support
2. Full exposed firebase analytics functionality to own blueprint library (do not requires default AnalyticsBlueprintLibrary plugin)
3. iOS support [Work in progress]

# Setup
1. Download version of plugin that support you're unreal project version
2. Place FirebaseAnalytics in you're Plugins folder in project (if don't exist needed to be created)
2.1 (if using C++ project) Right Mouse Click to .uproject file -> Generate Project Files 

# Setup usage
1. Open Firebase console and create project (follow the instructions on site)
2. Download google-services.json file
3. Place google-services.json into folder /Build/Android/gradle/app/ 
4. Set ProviderModuleName in [Analytics] section of you're /Config/DefaultEngine.ini to: FirebaseAnalytics 
  (https://docs.unrealengine.com/en-US/Gameplay/Analytics/Instrumenting/index.html)
5. Make sure plugin usage set to true in Plugin Browser. If there no issues, project will build&run without any errors. 

# Additional setup for C++ usage
1. Open you're IDE
2. Open /Source/projectname/projectname.build.cs file 
3. Add "FirebaseAnalytics" module to public module dependency list. 
4. Regenerate project files
5. Include "FirebaseAnalyticsBPLib.h" to any project files and check build for build errors. 

# Support & additional info
Feel free to do PR into this repository. Also feel free to use this plugin in you're own developer needs.
If you having some troubles with plugin or want some feature use Issues section.

You can support this project by giving it a star.
