#ifndef X_INFO_TYPEDEFS_HPP
#define X_INFO_TYPEDEFS_HPP

#include <string>

#define RAPIDJSON_HAS_STDSTRING 1

#if defined(XINFOLIBRARY_EXPORT)
#if defined _WIN32 || defined _WIN64
	#define XINFOAPI __declspec(dllexport)
#else
	#define XINFOAPI
#endif
#else
#if defined _WIN32 || defined _WIN64
	#define XINFOAPI __declspec(dllimport)
#else
	#define XINFOAPI
#endif
#endif

#ifndef JSON_PATH_SEPARATOR
#define JSON_PATH_SEPARATOR "/"
#endif

#endif // X_INFO_TYPEDEFS_HPP
