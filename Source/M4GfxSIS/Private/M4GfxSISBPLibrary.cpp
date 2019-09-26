// Copyright 019 Sheldon Robinson, Inc. All Rights Reserved.

#include "M4GfxSISBPLibrary.h"
#include "M4GfxSIS.h"
#include "m4gfx/sis/summary_manager.hpp"



UM4GfxSISBPLibrary::UM4GfxSISBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

const FSystemInfo UM4GfxSISBPLibrary::SysInfo() {
	FString JsonString(m4gfx::summary_manager::Instance()->GetSystemInformationSummary().get_data_as_string().c_str());
	TSharedRef< TJsonReader<TCHAR> > Reader = TJsonReaderFactory<TCHAR>::Create(JsonString);
	FSystemInfo  SysInfo;
	SysInfo.json = MakeShareable(new FJsonObject());
	if (FJsonSerializer::Deserialize<TCHAR>(Reader, SysInfo.json) && SysInfo.json.IsValid()) {
		UE_LOG(LogTemp, Log, TEXT("Created SysInfo Json"));
	}
	return SysInfo;
}

const FSystemInfoFields UM4GfxSISBPLibrary::SysInfoFieldNames() {
	FSystemInfoFields SysFields;
	for (auto sFieldname : m4gfx::summary_manager::Instance()->GetSystemInformationSummary().get_fields()) {
		FString Field(sFieldname.c_str());
		SysFields.fields.Add(Field);
	}
	return SysFields;
}

const FSystemInfoValue UM4GfxSISBPLibrary::SysInfoLookup(UPARAM(ref)  FSystemInfo& SysInfo, UPARAM(ref) const FString& FieldName) {
	FSystemInfoValue SysValue;
	if (SysInfo.json.IsValid()) {
		SysValue.value = SysInfo.json.Get()->TryGetField(FieldName);
	}
	return SysValue;
}


const FString UM4GfxSISBPLibrary::DisplaySysInfoValue(UPARAM(ref)  FSystemInfoValue& Value) {
	if (Value.value.IsValid()) {
		switch (Value.value.Get()->Type) {
			case EJson::None:
			case EJson::Null:
				UE_LOG(LogTemp, Log, TEXT("Display Empty System Value"));
				break;
			case EJson::String: {
					FString OutputString;
					if (Value.value.Get()->TryGetString(OutputString)) {
						UE_LOG(LogTemp, Log, TEXT("Display String System Value"));
					}
					return OutputString;
				}
				break;
			case EJson::Number:
				return FString::SanitizeFloat(Value.value.Get()->AsNumber());
				break;
			case EJson::Array: {
					FString OutputString;
					FPrettyJsonWriter JsonWriter = FPrettyJsonStringWriterFactory::Create(&OutputString);
					if (FJsonSerializer::Serialize(Value.value.Get()->AsArray(), JsonWriter, true)) {
						UE_LOG(LogTemp, Log, TEXT("Display Array System Value"));
					}
					return OutputString;
				}
				break;
			case EJson::Object: {
					FString OutputString;
					FPrettyJsonWriter JsonWriter = FPrettyJsonStringWriterFactory::Create(&OutputString);
					if (FJsonSerializer::Serialize(Value.value.Get()->AsObject().ToSharedRef(), JsonWriter, true)) {
						UE_LOG(LogTemp, Log, TEXT("Display Oject System Value"));
					}
					return OutputString;
				}
				break;
		}
	}
	return FString();
}


const FSystemInfoMap UM4GfxSISBPLibrary::GetSysInfoPropertyMap(UPARAM(ref)  FSystemInfo& SysInfo) {
	FSystemInfoMap pmap;
	if (SysInfo.json.IsValid()){
		 pmap.map.Append( SysInfo.json.Get()->Values);
	}
	return pmap;
}
