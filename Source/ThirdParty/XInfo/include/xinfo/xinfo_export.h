
#ifndef XINFO_API_H
#define XINFO_API_H

#ifdef XINFO_STATIC_DEFINE
#  define XINFO_API
#  define XINFO_NO_EXPORT
#else
#  ifndef XINFO_API
#    ifdef xinfo_EXPORTS
        /* We are building this library */
#      define XINFO_API __declspec(dllexport)
#    else
        /* We are using this library */
#      define XINFO_API __declspec(dllimport)
#    endif
#  endif

#  ifndef XINFO_NO_EXPORT
#    define XINFO_NO_EXPORT 
#  endif
#endif

#ifndef XINFO_DEPRECATED
#  define XINFO_DEPRECATED __declspec(deprecated)
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

#endif /* XINFO_API_H */
