# UE4FirebaseAnalytics
Free open source Firebase analytics provider for Unreal Engine 4. 

# Imrpotant notes: 
Plugin currently support only Android target platfrom, iOS work in progress.

# Setup
1. Download version of plugin that support you're unreal project version
2. Place FirebaseAnalytics in you're Plugins folder in project (if don't exist needed to be created)|
3. RMC to .uproject -> Generate Visual Studio files

Now you're free to use plugin. 

# Setup Firebase usage
1. Get into Firebase console & create you're project
2. Download google-services.json file
3. Place you're google-services.json into folder <projectdir>/Build/Android/gradle/app/ 
4. Select plugin usage to true in Plugin Browser and try to build Android. If there no issues, project will build without any errors. Please report any issues with build to Issues section

# Additional setup for C++ usage
1. Open you're IDE
2. Open <projectname>.build.cs file 
3. Add "FirebaseAnalytics" to you're dependency list. 

If everything right, you can try include "FirebaseAnalyticsBPLib.h" in some of project cpp files, try to build project with such plugin include. If you getting build error with include error, make sure dependency was right added to build.cs file. 


# Support & additional info
Feel free to do PR into this repository. Also feel free to use this plugin in you're own developer needs.

If you want to support this project, just give it a star.
