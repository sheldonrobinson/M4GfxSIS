// Copyright 2019 Sheldon Robinson. All Rights Reserved.

#ifndef XINFO_TEMPLATE_API_H
#define XINFO_TEMPLATE_API_H

#include <xinfo/xinfo_export.h>

#ifdef XINFO_STATIC_DEFINE
#  define XINFO_TEMPLATE_API
#else
#  ifndef XINFO_TEMPLATE_API
#    ifdef XINFO_EXPORTS
#		ifdef _MSC_VER
			/* We are building this library */
#      		define XINFO_TEMPLATE_API __declspec(dllexport)
#		else
			/* We are building this library */
#      		define XINFO_TEMPLATE_API __attribute__((visibility("default")))
#		endif
#    else
#		ifdef _MSC_VER
			/* We are using this library */
#			define XINFO_TEMPLATE_API __declspec(dllimport)
#		else
			/* We are using this library */
#      		define XINFO_TEMPLATE_API __attribute__((visibility("default")))
#		endif
#    endif
#  endif

#endif

#pragma warning (default : 4668)

#endif
