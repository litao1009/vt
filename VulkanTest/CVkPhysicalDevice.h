#pragma once

#include "VKHeader.h"

#include <vector>

class CVkPhysicalDevice
{
public:
    VkPhysicalDevice                     PhysicalDevice;
    VkPhysicalDeviceProperties           PhysicalDeviceProperties;
    VkPhysicalDeviceFeatures             PhysicalDeviceFeatures;
    VkPhysicalDeviceMemoryProperties     PhysicalDeviceMemoryProperties;
    std::vector<VkQueueFamilyProperties> QueueFamilyProperties;
    std::vector<VkLayerProperties>       PhysicalDeviceLayerProperties;
    std::vector<VkExtensionProperties>   PhysicalDeviceExtensionProperties;
};