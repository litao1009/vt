#pragma once

#include "VKHeader.h"
#include "InstanceFunctionTable.h"
#include "CVkPhysicalDevice.h"

#include <vector>

class CVkInstance
{
public://Handle
    VkInstance InstanceHandle = VK_NULL_HANDLE;

public://Parameter
    VkApplicationInfo AppInfo = {
        //sType
        VK_STRUCTURE_TYPE_APPLICATION_INFO,
        //pNext
        nullptr,
        //pApplicationName
        "AppName",
        //applicationVersion
        VK_MAKE_VERSION( 0, 0, 1 ),
        //pEngineName
        "EngineName",
        //apiVersion
        VK_API_VERSION_1_1};
    VkInstanceCreateInfo CreateInfo = {
        //sType
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        //pNext
        nullptr,
        //flags
        0,
        //pApplicationInfo
        &AppInfo,
        //enabledLayerCount
        0,
        //ppEnabledLayerNames
        nullptr,
        //enabledExtensionCount
        0,
        //ppEnabledExtensionNames
        nullptr};
    std::vector<const char*> EnabledLayers;
    std::vector<const char*> EnabledExtensions;
    VkAllocationCallbacks*   AllocationCallbacks{};

public://Query
    std::vector<CVkPhysicalDevice> EnumeratePhysicalDevices;
    InstanceFunctionTable          FunctionTable;

public:
    bool Create();

    bool Destory();
};