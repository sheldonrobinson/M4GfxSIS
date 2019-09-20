
// This is a generated file. Do not edit!

#ifndef XINFO_COMPILER_DETECTION_H
#define XINFO_COMPILER_DETECTION_H

#ifdef __cplusplus
# define XINFO_COMPILER_IS_Comeau 0
# define XINFO_COMPILER_IS_Intel 0
# define XINFO_COMPILER_IS_PathScale 0
# define XINFO_COMPILER_IS_Embarcadero 0
# define XINFO_COMPILER_IS_Borland 0
# define XINFO_COMPILER_IS_Watcom 0
# define XINFO_COMPILER_IS_OpenWatcom 0
# define XINFO_COMPILER_IS_SunPro 0
# define XINFO_COMPILER_IS_HP 0
# define XINFO_COMPILER_IS_Compaq 0
# define XINFO_COMPILER_IS_zOS 0
# define XINFO_COMPILER_IS_XLClang 0
# define XINFO_COMPILER_IS_XL 0
# define XINFO_COMPILER_IS_VisualAge 0
# define XINFO_COMPILER_IS_PGI 0
# define XINFO_COMPILER_IS_Cray 0
# define XINFO_COMPILER_IS_TI 0
# define XINFO_COMPILER_IS_Fujitsu 0
# define XINFO_COMPILER_IS_GHS 0
# define XINFO_COMPILER_IS_SCO 0
# define XINFO_COMPILER_IS_ARMCC 0
# define XINFO_COMPILER_IS_AppleClang 0
# define XINFO_COMPILER_IS_ARMClang 0
# define XINFO_COMPILER_IS_Clang 0
# define XINFO_COMPILER_IS_GNU 0
# define XINFO_COMPILER_IS_MSVC 0
# define XINFO_COMPILER_IS_ADSP 0
# define XINFO_COMPILER_IS_IAR 0
# define XINFO_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef XINFO_COMPILER_IS_Comeau
# define XINFO_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef XINFO_COMPILER_IS_Intel
# define XINFO_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef XINFO_COMPILER_IS_PathScale
# define XINFO_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef XINFO_COMPILER_IS_Embarcadero
# define XINFO_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef XINFO_COMPILER_IS_Borland
# define XINFO_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef XINFO_COMPILER_IS_Watcom
# define XINFO_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef XINFO_COMPILER_IS_OpenWatcom
# define XINFO_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef XINFO_COMPILER_IS_SunPro
# define XINFO_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef XINFO_COMPILER_IS_HP
# define XINFO_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef XINFO_COMPILER_IS_Compaq
# define XINFO_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef XINFO_COMPILER_IS_zOS
# define XINFO_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef XINFO_COMPILER_IS_XLClang
# define XINFO_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef XINFO_COMPILER_IS_XL
# define XINFO_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef XINFO_COMPILER_IS_VisualAge
# define XINFO_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef XINFO_COMPILER_IS_PGI
# define XINFO_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef XINFO_COMPILER_IS_Cray
# define XINFO_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef XINFO_COMPILER_IS_TI
# define XINFO_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef XINFO_COMPILER_IS_Fujitsu
# define XINFO_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef XINFO_COMPILER_IS_GHS
# define XINFO_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef XINFO_COMPILER_IS_SCO
# define XINFO_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef XINFO_COMPILER_IS_ARMCC
# define XINFO_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef XINFO_COMPILER_IS_AppleClang
# define XINFO_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef XINFO_COMPILER_IS_ARMClang
# define XINFO_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef XINFO_COMPILER_IS_Clang
# define XINFO_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef XINFO_COMPILER_IS_GNU
# define XINFO_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef XINFO_COMPILER_IS_MSVC
# define XINFO_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef XINFO_COMPILER_IS_ADSP
# define XINFO_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef XINFO_COMPILER_IS_IAR
# define XINFO_COMPILER_IS_IAR 1


#endif

#  if XINFO_COMPILER_IS_AppleClang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 400)
#      error Unsupported compiler version
#    endif

# define XINFO_COMPILER_VERSION_MAJOR (__clang_major__)
# define XINFO_COMPILER_VERSION_MINOR (__clang_minor__)
# define XINFO_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define XINFO_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define XINFO_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# define XINFO_COMPILER_VERSION_TWEAK (__apple_build_version__)

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define XINFO_COMPILER_CXX_ALIGNAS 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define XINFO_COMPILER_CXX_ALIGNOF 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_constexpr)
#      define XINFO_COMPILER_CXX_CONSTEXPR 1
#    else
#      define XINFO_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_override_control)
#      define XINFO_COMPILER_CXX_FINAL 1
#    else
#      define XINFO_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_noexcept)
#      define XINFO_COMPILER_CXX_NOEXCEPT 1
#    else
#      define XINFO_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_nullptr)
#      define XINFO_COMPILER_CXX_NULLPTR 1
#    else
#      define XINFO_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_thread_local)
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif XINFO_COMPILER_IS_Clang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 301)
#      error Unsupported compiler version
#    endif

# define XINFO_COMPILER_VERSION_MAJOR (__clang_major__)
# define XINFO_COMPILER_VERSION_MINOR (__clang_minor__)
# define XINFO_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define XINFO_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define XINFO_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alignas)
#      define XINFO_COMPILER_CXX_ALIGNAS 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alignas)
#      define XINFO_COMPILER_CXX_ALIGNOF 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_constexpr)
#      define XINFO_COMPILER_CXX_CONSTEXPR 1
#    else
#      define XINFO_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_override_control)
#      define XINFO_COMPILER_CXX_FINAL 1
#    else
#      define XINFO_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_noexcept)
#      define XINFO_COMPILER_CXX_NOEXCEPT 1
#    else
#      define XINFO_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_nullptr)
#      define XINFO_COMPILER_CXX_NULLPTR 1
#    else
#      define XINFO_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_thread_local)
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif XINFO_COMPILER_IS_GNU

#    if !((__GNUC__ * 100 + __GNUC_MINOR__) >= 404)
#      error Unsupported compiler version
#    endif

# if defined(__GNUC__)
#  define XINFO_COMPILER_VERSION_MAJOR (__GNUC__)
# else
#  define XINFO_COMPILER_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define XINFO_COMPILER_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define XINFO_COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define XINFO_COMPILER_CXX_ALIGNAS 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNAS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define XINFO_COMPILER_CXX_ALIGNOF 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNOF 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define XINFO_COMPILER_CXX_CONSTEXPR 1
#    else
#      define XINFO_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define XINFO_COMPILER_CXX_FINAL 1
#    else
#      define XINFO_COMPILER_CXX_FINAL 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define XINFO_COMPILER_CXX_NOEXCEPT 1
#    else
#      define XINFO_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define XINFO_COMPILER_CXX_NULLPTR 1
#    else
#      define XINFO_COMPILER_CXX_NULLPTR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif XINFO_COMPILER_IS_MSVC

#    if !(_MSC_VER >= 1600)
#      error Unsupported compiler version
#    endif

  /* _MSC_VER = VVRR */
# define XINFO_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define XINFO_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define XINFO_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define XINFO_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define XINFO_COMPILER_VERSION_TWEAK (_MSC_BUILD)
# endif

#    if _MSC_VER >= 1900
#      define XINFO_COMPILER_CXX_ALIGNAS 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNAS 0
#    endif

#    if _MSC_VER >= 1900
#      define XINFO_COMPILER_CXX_ALIGNOF 1
#    else
#      define XINFO_COMPILER_CXX_ALIGNOF 0
#    endif

#    if _MSC_VER >= 1900
#      define XINFO_COMPILER_CXX_CONSTEXPR 1
#    else
#      define XINFO_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if _MSC_VER >= 1700
#      define XINFO_COMPILER_CXX_FINAL 1
#    else
#      define XINFO_COMPILER_CXX_FINAL 0
#    endif

#    if _MSC_VER >= 1900
#      define XINFO_COMPILER_CXX_NOEXCEPT 1
#    else
#      define XINFO_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if _MSC_VER >= 1600
#      define XINFO_COMPILER_CXX_NULLPTR 1
#    else
#      define XINFO_COMPILER_CXX_NULLPTR 0
#    endif

#    if _MSC_VER >= 1900
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define XINFO_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if _MSC_VER >= 1900
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define XINFO_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if defined(XINFO_COMPILER_CXX_ALIGNAS) && XINFO_COMPILER_CXX_ALIGNAS
#    define XINFO_ALIGNAS(X) alignas(X)
#  elif XINFO_COMPILER_IS_GNU || XINFO_COMPILER_IS_Clang || XINFO_COMPILER_IS_AppleClang
#    define XINFO_ALIGNAS(X) __attribute__ ((__aligned__(X)))
#  elif XINFO_COMPILER_IS_MSVC
#    define XINFO_ALIGNAS(X) __declspec(align(X))
#  else
#    define XINFO_ALIGNAS(X)
#  endif


#  if defined(XINFO_COMPILER_CXX_ALIGNOF) && XINFO_COMPILER_CXX_ALIGNOF
#    define XINFO_ALIGNOF(X) alignof(X)
#  elif XINFO_COMPILER_IS_GNU || XINFO_COMPILER_IS_Clang || XINFO_COMPILER_IS_AppleClang
#    define XINFO_ALIGNOF(X) __alignof__(X)
#  elif XINFO_COMPILER_IS_MSVC
#    define XINFO_ALIGNOF(X) __alignof(X)
#  endif


#  if defined(XINFO_COMPILER_CXX_CONSTEXPR) && XINFO_COMPILER_CXX_CONSTEXPR
#    define XINFO_CONSTEXPR constexpr
#  else
#    define XINFO_CONSTEXPR 
#  endif


#  if defined(XINFO_COMPILER_CXX_FINAL) && XINFO_COMPILER_CXX_FINAL
#    define XINFO_FINAL final
#  else
#    define XINFO_FINAL 
#  endif


#  if defined(XINFO_COMPILER_CXX_NOEXCEPT) && XINFO_COMPILER_CXX_NOEXCEPT
#    define XINFO_NOEXCEPT noexcept
#    define XINFO_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define XINFO_NOEXCEPT
#    define XINFO_NOEXCEPT_EXPR(X)
#  endif


#  if defined(XINFO_COMPILER_CXX_NULLPTR) && XINFO_COMPILER_CXX_NULLPTR
#    define XINFO_NULLPTR nullptr
#  elif XINFO_COMPILER_IS_GNU
#    define XINFO_NULLPTR __null
#  else
#    define XINFO_NULLPTR 0
#  endif


#  if defined(XINFO_COMPILER_CXX_THREAD_LOCAL) && XINFO_COMPILER_CXX_THREAD_LOCAL
#    define XINFO_THREAD_LOCAL thread_local
#  elif XINFO_COMPILER_IS_GNU || XINFO_COMPILER_IS_Clang || XINFO_COMPILER_IS_AppleClang
#    define XINFO_THREAD_LOCAL __thread
#  elif XINFO_COMPILER_IS_MSVC
#    define XINFO_THREAD_LOCAL __declspec(thread)
#  else
// XINFO_THREAD_LOCAL not defined for this configuration.
#  endif

#endif

#endif
