#pragma once

#include "VKHeader.h"
#include "InstanceFunctionTable.h"

#include <vector>
#include <map>

class CVkPhysicalDevice
{
public:
    VkPhysicalDevice PhysicalDeviceHandle;

public:
    InstanceFunctionTable                  InstanceFunctions{};
    VkPhysicalDeviceProperties             PhysicalDeviceProperties;
    VkPhysicalDeviceFeatures               PhysicalDeviceFeatures;
    VkPhysicalDeviceMemoryProperties       PhysicalDeviceMemoryProperties;
    std::vector<VkQueueFamilyProperties>   QueueFamilyProperties;
    std::vector<VkLayerProperties>         PhysicalDeviceLayerProperties;
    std::vector<VkExtensionProperties>     PhysicalDeviceExtensionProperties;
    std::map<VkFormat, VkFormatProperties> FormatProperties;

public:
    void Query();
};