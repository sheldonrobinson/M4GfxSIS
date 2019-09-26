// Copyright 2019 Sheldon Robinson. All Rights Reserved.

#include "XInfoPlugin.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FXInfoModule"

void FXInfoPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("M4GfxSIS")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/XInfoLibrary/Win64/xinfo.dll"));
#elif PLATFORM_LINUX
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/XInfoLibrary/Linux/libxinfo.so"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/XInfoLibrary/Mac/Release/libxinfo.dylib"));
#endif // PLATFORM_WINDOWS

	XInfoLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (XInfoLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		UE_LOG(LogTemp, Log, TEXT("Loaded third party library"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("ThirdPartyLibraryError: Failed to load xinfo third party library"));
	}
}

void FXInfoPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(XInfoLibraryHandle);
	XInfoLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXInfoPluginModule, XInfoPlugin)
