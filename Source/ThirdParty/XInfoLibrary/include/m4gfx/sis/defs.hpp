#ifndef X_INFO_TYPEDEFS_HPP
#define X_INFO_TYPEDEFS_HPP

#include <boost/predef/hardware/simd.h>
#include <boost/predef/make.h>
#include <boost/preprocessor/stringize.hpp>

#if BOOST_PREDEF_MAKE_10_VRP(BOOST_HW_SIMD_X86) >= BOOST_PREDEF_MAKE_10_VRP(BOOST_HW_SIMD_X86_SSE4_1_VERSION)
#define BOOST_UUID_USE_SSE41 1
#elif BOOST_PREDEF_MAKE_10_VRP(BOOST_HW_SIMD_X86) >= BOOST_PREDEF_MAKE_10_VRP(BOOST_HW_SIMD_X86_SSE3_VERSION)
#define BOOST_UUID_USE_SSE3 1
#elif BOOST_PREDEF_MAKE_10_VRP(BOOST_HW_SIMD_X86) >= BOOST_PREDEF_MAKE_10_VRP(BOOST_HW_SIMD_X86_SSE2_VERSION)
#define  BOOST_UUID_USE_SSE2 1
#endif

#include <boost/uuid/uuid.hpp>
#include <string>

#define RAPIDJSON_HAS_STDSTRING 1

#if defined _WIN32 || defined _WIN64
	#define DLLIMPORT __declspec(dllimport)
#else
	#define DLLIMPORT
#endif

namespace m4gfx
{

enum XINFOCLASS {
    XIC_NONE = 0,
    XIC_SUMMARY = 1,
    XIC_SESSION = 2,
    XIC_ENVIRONMENT = 3,
    XIC_OS = 4,
    XIC_OS_INSTANCES = 5,
    XIC_CPU = 6,
    XIC_PROCESSORS = 7,
    XIC_GPU = 8,
    XIC_GRAPHICS_DEVICES = 9,
    XIC_OPENGL = 10,
    XIC_GL_RENDERERS = 10,
    XIC_OPENCL = 11,
    XIC_CL_ACCELERATORS = 12,
    XIC_VULKAN = 13,
    XIC_VK_RUNTIMES = 14,
    XIC_CUSTOM = 15
       
};

  static const std::string x_info_class_names[] = { "", "Summary", "Sessions", "Environments", 
                            "OperatingSystem", "OperatingSystemInstances", "CPU", "Processors",
                            "GPU", "GraphicsDevices", "OpenGL", "GL_Renderers", "OpenCL", "CL_Accelerators",
                            "Vulkan", "VulkanRuntimes", "Custom"};

enum M4GFX_SESSION_MODE {
    M4GFX_SERVER_SESSION,
    M4GFX_CLIENT_SESSION,
    M4GFX_GAME_SESSION,
    M4GFX_EDITOR_SESSION
};

enum M4GFX_ENV_TYPE {
    M4GFX_VIRTUAL_ENV,
    M4GFX_NATIVE_ENV,
    M4GFX_EMULATOR_ENV
};

enum ENV_ROLE {
    M4GFX_HOST_ROLE,
    M4GFX_CLIENT_ROLE,
    M4GFX_SERVER_ROLE
};
}

#endif // X_INFO_TYPEDEFS_HPP