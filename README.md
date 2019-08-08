# UE4FirebaseAnalytics
Free open source Firebase analytics provider for Unreal Engine 4. 

# Imrpotant notes: 
Plugin currently support only Android target platfrom, iOS work in progress.
Current supported engine version: 4.21.3 (master branch)

# Features
1. Free 2 use
2. Android multiple CPU architecture support
3. Full exposed firebase analytics functionality to own blueprint library (do not requires default AnalyticsBlueprintLibrary plugin)
4. iOS support [Work in progress]

# Setup
1. Download version of plugin that support you're unreal project version
2. Place FirebaseAnalytics in you're Plugins folder in project (if don't exist needed to be created)
2.1 (if using C++ project) RMC to .uproject file -> Generate Project Files 
3. Open project and enable plugin in Plugin Browser

Now you're free to use plugin. 

# Setup Firebase connection
1. Get into Firebase console & create project
2. Download google-services.json file
3. Place google-services.json into folder <projectdir>/Build/Android/gradle/app/ 
4. Select plugin usage to true in Plugin Browser and try to build Android. If there no issues, project will build&run without any errors. 
Please report any issues to Issues section

# Additional setup for C++ usage
1. Open you're IDE
2. Open <projectname>.build.cs file 
3. Add "FirebaseAnalytics" to public module dependency list. 
4. Include "FirebaseAnalyticsBPLib.h" to any project code files and check build for build errors. 

# Support & additional info
Feel free to do PR into this repository. Also feel free to use this plugin in you're own developer needs.
If you having some problems with plugin or want some feature use Issues section.

You can support this project by giving it a star.
