#include "CVkDevice.h"

bool CVkDevice::Create()
{
    auto ret = Instance->vkCreateDevice( PhysicalDevice.PhysicalDevice, &DeviceCreateInfo, nullptr, &Device );
    return ret == VK_SUCCESS;
}

void CVkDevice::Destory()
{
    Instance->vkDestroyDevice( Device, nullptr );
}
