// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class XInfoLibrary : ModuleRules
{
	public XInfoLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		// Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/"));

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,  "include"));

		string ThirdPartyBinariesDir = Path.Combine("$(EngineDir)","Binaries", "ThirdParty", "XInfoLibrary");

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicLibraryPaths.Add(Path.Combine(ThirdPartyBinariesDir, "Win64"));
			PublicAdditionalLibraries.Add("xinfo.lib");
			PublicAdditionalLibraries.Add("cpu_features.lib");
			PublicAdditionalLibraries.Add("GLEW.lib");

			// Dynamic
            		RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Win64", "xinfo.dll"));
			RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Win64", "cpu_features.dll"));
			RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Win64", "GLEW.dll"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("xinfo.dll");
			PublicDelayLoadDLLs.Add("cpu_features.dll");
			PublicDelayLoadDLLs.Add("GLEW.dll");
		}
        else if(Target.Platform == UnrealTargetPlatform.Linux)
        {
			// Add the import library
			PublicLibraryPaths.Add(Path.Combine(ThirdPartyBinariesDir, "Linux"));
			PublicAdditionalLibraries.Add("xinfo");
			PublicAdditionalLibraries.Add("cpu_features");
			PublicAdditionalLibraries.Add("GLEW");

			// Dynamic
            RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Linux", "libxinfo.so"));
			RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Linux", "libcpu_features.so"));
			RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Linux", "libGLEW.so"));

        }
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{

			// Dynamic
            RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Mac", "libxinfo.dylib"));
			RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Mac", "libcpu_features.dylib"));
			RuntimeDependencies.Add(Path.Combine(ThirdPartyBinariesDir, "Mac", "libGLEW.dylib"));

			PublicLibraryPaths.Add(Path.Combine(ThirdPartyBinariesDir, "Mac"));
		    PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "libxinfo.dylib"));
			PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "libcpu_features.dylib"));
			PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "libGLEW.dylib"));
		}
	}
}
