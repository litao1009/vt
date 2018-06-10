#pragma once

#include "VKHeader.h"

#include <vector>

class CVkGlobalInfo
{
public:
    std::vector<VkLayerProperties>     EnumerateInstanceLayerProperties;
    std::vector<VkExtensionProperties> EnumerateInstanceExtensionProperties;
    uint32_t                           MajorVersion{};
    uint32_t                           MinorVersion{};
    uint32_t                           PatchVersion{};

public:
    static CVkGlobalInfo& GetInstance();

public:
    void QueryInstanceInfo();
};