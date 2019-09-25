// Copyright 2019 Sheldon Robinson. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FM4GfxSISModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
