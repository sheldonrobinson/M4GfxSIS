// Copyright 2019 Sheldon Robinson. All Rights Reserved.

#ifndef XINFO_TEMPLATE_API_H
#define XINFO_TEMPLATE_API_H

#include <xinfo/xinfo_export.h>

#ifdef XINFO_STATIC_DEFINE
#  define XINFO_TEMPLATE_API
#else
#  ifndef XINFO_TEMPLATE_API
#    ifdef XINFO_EXPORTS
        /* We are building this library */
#      define XINFO_TEMPLATE_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define XINFO_TEMPLATE_API __attribute__((visibility("default")))
#    endif
#  endif

#endif

#pragma warning (default : 4668)

#endif