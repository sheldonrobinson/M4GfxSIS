// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class XInfoLib : ModuleRules
{
	public XInfoLib(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string PlatformName = Target.Platform.ToString();
		string IncPath = Path.Combine(ModuleDirectory, "include");
		string LibPath = Path.Combine(ModuleDirectory, PlatformName);
		string BinaryPath = Path.GetFullPath(Path.Combine(ModuleDirectory, PlatformName));
		
		PublicSystemIncludePaths.Add(IncPath);
		PublicLibraryPaths.Add(LibPath);
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,  "include"));

        PublicDefinitions.AddRange(new string[] { "FMT_HEADER_ONLY=1", "RAPIDJSON_HAS_STDSTRING=1", "GLEW_STATIC=1" });


        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicAdditionalLibraries.Add("xinfo.lib");
			string DLLName = "xinfo.dll";
			// Dynamic
            		RuntimeDependencies.Add(Path.Combine(LibPath, DLLName));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add(DLLName);
			RuntimeDependencies.Add(Path.Combine(BinaryPath, DLLName));
		}
        else if(Target.Platform == UnrealTargetPlatform.Linux)
        {
			// Add the import library
			PublicAdditionalLibraries.Add("xinfo");

			// Dynamic
            		RuntimeDependencies.Add(Path.Combine(LibPath, "libxinfo.so"));
			
			RuntimeDependencies.Add(Path.Combine(BinaryPath, "libxinfo.so"));

        }
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			string DLLName = "libxinfo.dylib";

			// Dynamic
            		RuntimeDependencies.Add(Path.Combine(LibPath, DLLName));
			
			RuntimeDependencies.Add(Path.Combine(BinaryPath, DLLName));
		    PublicDelayLoadDLLs.Add(Path.Combine(LibPath, DLLName));
		}
	}
}
