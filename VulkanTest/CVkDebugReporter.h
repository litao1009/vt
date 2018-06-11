#pragma once

#include "VKHeader.h"

#include "InstanceFunctionTable.h"

class CVkDebugReporter
{
    VkDebugReportCallbackCreateInfoEXT CreateInfo;
    VkInstance                         Instance = VK_NULL_HANDLE;
    VkDebugReportCallbackEXT           Handle = VK_NULL_HANDLE;

private:
    static VkBool32 VKAPI_CALL DebugReportCallbackEXT( VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode,
                                                       const char* pLayerPrefix, const char* pMessage, void* pUserData );

private:
    VkBool32 _DebugReportCallbackEXT( VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode,
                                      const char* pLayerPrefix, const char* pMessage );

public:
    void Init( VkInstance instace );

    void UnInit();
};