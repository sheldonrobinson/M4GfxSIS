// Copyright 2019 Sheldon Robinson. All Rights Reserved.

#ifndef XINFO_API_H
#define XINFO_API_H

#ifdef XINFO_STATIC_DEFINE
#  define XINFO_API
#  define XINFO_NO_EXPORT
#else
#  ifndef XINFO_API
#    ifdef xinfo_EXPORTS
#		ifdef _MSC_VER
			/* We are building this library */
#			define XINFO_API __declspec(dllexport)
#		else
			/* We are building this library */
#			define XINFO_API __attribute__((visibility("default")))
#		endif
#    else
#		ifdef _MSC_VER
			/* We are using this library */
#			define XINFO_API __declspec(dllimport)
#		else
			/* We are using this library */
#			define XINFO_API __attribute__((visibility("default")))
#		endif
#    endif
#  endif

#  ifndef XINFO_NO_EXPORT
#		ifdef _MSC_VER
#			define XINFO_NO_EXPORT
#		else
#			define XINFO_NO_EXPORT __attribute__((visibility("hidden")))
#		endif
#  endif
#endif

#ifndef XINFO_DEPRECATED
#	ifdef _MSC_VER
#		define XINFO_DEPRECATED __declspec(deprecated)
#	else
#		define XINFO_DEPRECATED __attribute__ ((__deprecated__))
#	endif
#endif

#ifndef XINFO_DEPRECATED_EXPORT
#  define XINFO_DEPRECATED_EXPORT XINFO_API XINFO_DEPRECATED
#endif

#ifndef XINFO_DEPRECATED_NO_EXPORT
#  define XINFO_DEPRECATED_NO_EXPORT XINFO_NO_EXPORT XINFO_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef XINFO_NO_DEPRECATED
#    define XINFO_NO_DEPRECATED
#  endif
#endif

#endif
