#pragma once

#define VK_NO_PROTOTYPES
#include "vulkan/vulkan.h"

#ifdef LOADER
#define DECLARE_VK_GLOBAL_FUNC( func ) PFN_##func func{};
#else
#define DECLARE_VK_GLOBAL_FUNC( func ) extern PFN_##func func;
#endif// LOADER

DECLARE_VK_GLOBAL_FUNC( vkGetInstanceProcAddr )

DECLARE_VK_GLOBAL_FUNC( vkCreateInstance )
DECLARE_VK_GLOBAL_FUNC( vkEnumerateInstanceExtensionProperties )
DECLARE_VK_GLOBAL_FUNC( vkEnumerateInstanceLayerProperties )
DECLARE_VK_GLOBAL_FUNC( vkEnumerateInstanceVersion )