#pragma once

#include "VKHeader.h"
#include "CVkPhysicalDevice.h"
#include "CVkInstance.h"

class CVkDevice
{
public:
    VkDevice DeviceHandle = VK_NULL_HANDLE;

public:
    VkDeviceCreateInfo DeviceCreateInfo = {
        //SType
        VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        //pNext
        nullptr,
        //flags
        0,
        //queueCreateInfoCount
        0,
        //pQueueCreateInfos
        nullptr,
        //enabledLayerCount
        0,
        //ppEnabledLayerNames
        nullptr,
        //enabledExtensionCount
        0,
        //ppEnabledEnxtensionNames
        nullptr,
        //pEnabledFeatrues
        nullptr};
    CVkPhysicalDevice                    PhysicalDevice;
    VkAllocationCallbacks*               AllocationCallbacks{};
    std::vector<VkDeviceQueueCreateInfo> DeviceQueueCreateInfo;

public:
    bool Create();

    void Destory();
};