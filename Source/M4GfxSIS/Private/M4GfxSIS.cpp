// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "M4GfxSIS.h"
#include "M4GfxSISPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FM4GfxSISModule"

void FM4GfxSISModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(m4gfx::summary_manager::Instance()->GetSystemInformationSummary().get_data_as_string() );
	
}

void FM4GfxSISModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FM4GfxSISModule, M4GfxSIS)