
#ifndef XINFO_API_H
#define XINFO_API_H

#ifdef XINFO_STATIC_DEFINE
#  define XINFO_API
#  define XINFO_NO_EXPORT
#else
#  ifndef XINFO_API
#    ifdef xinfo_EXPORTS
        /* We are building this library */
#      define XINFO_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define XINFO_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef XINFO_NO_EXPORT
#    define XINFO_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef XINFO_DEPRECATED
#  define XINFO_DEPRECATED __attribute__ ((__deprecated__))
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
