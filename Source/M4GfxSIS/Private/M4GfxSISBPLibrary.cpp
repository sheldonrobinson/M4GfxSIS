// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "M4GfxSISBPLibrary.h"
#include "M4GfxSIS.h"
#include "Json.h"

UM4GfxSISBPLibrary::UM4GfxSISBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UM4GfxSISBPLibrary::M4GfxSISSampleFunction(float Param)
{
	return -1;
}

/*
struct JsonCracker {
	enum JsonDataType {
		JSON_BOOLEAN =0,
		JSON_NUMBER,
		JSON_NULL,
		JSON_STRING,
		JSON_Array,
		JSON_OBJECT
	};

	JsonDataType type;

	union JsonData {
		FJsonValueNull nullValue,
		FJsonValueBoolean booleanValue,
		FJsonValueNumber numberValue,
		FJsonValueString stringValue,
		FJsonValueArry arrayValue,
		FJsonValueObject objectValue
	};

	JsonCracker(JsonDataType t): type(t){
		switch(type){
			case JsonDataType::JSON_BOOLEAN:
				new (&booleanValue) bool();
				break;
			case JsonDataType::JSON_NUMBER:
				new (&longValue) int64();
				break;
			case JsonDataType::JSON_NULL:
				IsNull=true;
				break;
			case JsonDataType::JSON_STRING:
				new (&stringValue) FString();
				break;
			case JsonDataType::JSON_Array:
				new (&arrayValue) TArray<FString>();
				break;
			default:
				new (&objectValue) TSharedPtr<FJsonObject>();
				break;
		}
	}

	~JsonCracker(){
		switch(type){
			case JsonDataType::JSON_BOOLEAN:
				booleanValue.~bool();
				break;
			case JsonDataType::JSON_NUMBER:
				longValue.~int64();
				break;
			case JsonDataType::JSON_STRING:
				stringValue.~FString();
				break;
			case JsonDataType::JSON_Array:
				arrayValue.~TArray<FString>();
				break;
			case JsonDataType::JSON_OBJECT
				objectValue.~TSharedPtr<FJsonObject>();
				break;
		}
	}
};*/

