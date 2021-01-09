# UE4_FirebaseAnalytics
Firebase analytics provider for Unreal Engine 4. 

# Imrpotant notes: 
Plugin currently support only Android target platfrom, iOS not currently working (if you can finish the job, please feel free to do PR).
Current supported engine version: 4.25.* (master branch)

# Setup
1. Download plugin
2. Place FirebaseAnalytics in Plugins folder in your project (if don't exist needed to be created)
2.1 (if using C++) Right Mouse Click to .uproject file -> Generate Project Files 
3. Open Firebase console and create project (follow the instructions on site)
4. Download google-services.json file
5. Place google-services.json into folder ProjectFolder/Build/Android/gradle/app/ 
6. Open Config/DefaultEngine.ini file and add:
```
[Analytics]
ProviderModuleName=FirebaseAnalytics
```
7. Make sure plugin usage set to true in Plugin Browser. If there no issues, project will build&run without any errors. 

# Additional setup for C++ usage
1. Open IDE
2. Open /Source/projectname/projectname.build.cs file 
3. Add "FirebaseAnalytics" module to public module dependency list. 

# Support & additional info
Feel free to do PR into this repository. Also feel free to use this plugin in you're own developer needs.
If you having some troubles with plugin or want some feature use Issues section.

You can support this project by giving it a star.
