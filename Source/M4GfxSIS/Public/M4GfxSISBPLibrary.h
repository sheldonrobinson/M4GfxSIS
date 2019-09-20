// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Json.h"
#include "M4GfxSISBPLibrary.generated.h"



/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
USTRUCT(BlueprintType, Category = "M4GfxSIS|Information")
struct FSystemInfo {
public:
	GENERATED_USTRUCT_BODY()

	TSharedPtr<FJsonObject> json;
};

USTRUCT(BlueprintType, Category = "M4GfxSIS|Information")
struct FSystemInfoMap {
public:
	GENERATED_USTRUCT_BODY()

	TMap<FString, TSharedPtr<FJsonValue> > map;
};

USTRUCT(BlueprintType, Category = "M4GfxSIS|Information")
struct FSystemInfoFields {
public:
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "List of System Properties", Category = "M4GfxSIS|Information")
	TSet<FString> fields;

};

USTRUCT(BlueprintType, Category = "M4GfxSIS|Information")
struct FSystemInfoValue {
public:
	GENERATED_USTRUCT_BODY()

	TSharedPtr<FJsonValue> value;

};

UCLASS(BlueprintType, Category = "M4GfxSIS|Information")
class UM4GfxSISBPLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_UCLASS_BODY()

	typedef TSharedRef< TJsonWriter< TCHAR, TPrettyJsonPrintPolicy< TCHAR > > > FPrettyJsonWriter;
	typedef TJsonWriterFactory< TCHAR, TPrettyJsonPrintPolicy< TCHAR > > FPrettyJsonStringWriterFactory;


	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get System Information", Keywords = "M4GfxSIS System Information"), Category = "M4GfxSIS|Information")
	static const FSystemInfo SysInfo();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get System Information Field Names", Keywords = "M4GfxSIS System Information"), Category = "M4GfxSIS|Information")
	static const FSystemInfoFields SysInfoFieldNames();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get System Information Value", Keywords = "M4GfxSIS System Information"), Category = "M4GfxSIS|Information")
	static const FSystemInfoValue SysInfoLookup(UPARAM(ref)  FSystemInfo& SysInfo, UPARAM(ref) const FString& FieldName);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Display System Information Field Value", Keywords = "M4GfxSIS System Information"), Category = "M4GfxSIS|Information")
	static const FString DisplaySysInfoValue(UPARAM(ref)  FSystemInfoValue& Value);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Display System Information Properties", Keywords = "M4GfxSIS System Information"), Category = "M4GfxSIS|Information")
	static const FSystemInfoMap GetSysInfoPropertyMap(UPARAM(ref)  FSystemInfo& SysInfo);
};
