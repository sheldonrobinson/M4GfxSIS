// Some copyright should be here...

using UnrealBuildTool;

public class M4GfxSIS : ModuleRules
{
	public M4GfxSIS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				System.IO.Path.Combine(ModuleDirectory, "Public"),
				System.IO.Path.Combine(ModuleDirectory, "..", "ThirdParty", "XInfoLibrary", "include")
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				System.IO.Path.Combine(ModuleDirectory, "Private"),
				System.IO.Path.Combine(ModuleDirectory, "..", "ThirdParty", "XInfoLibrary", "include")
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"XInfoLibrary",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects",
				"JSON"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		if(Target.Platform ==UnrealTargetPlatform.Win64){
				PublicLibraryPaths.Add(System.IO.Path.Combine(ModuleDirectory, "..", "ThirdParty", "XInfoLibrary","Win64"));
		}
		if(Target.Platform ==UnrealTargetPlatform.Linux){
				PublicLibraryPaths.Add(System.IO.Path.Combine(ModuleDirectory, "..", "ThirdParty", "XInfoLibrary","Linux"));
		}
		if(Target.Platform ==UnrealTargetPlatform.Mac){
				PublicLibraryPaths.Add(System.IO.Path.Combine(ModuleDirectory, "..", "ThirdParty", "XInfoLibrary","Mac"));
		}
	}
}
