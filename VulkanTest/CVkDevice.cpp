#include "CVkDevice.h"

bool CVkDevice::Create()
{
    if ( !DeviceQueueCreateInfo.empty() )
    {
        DeviceCreateInfo.queueCreateInfoCount = DeviceQueueCreateInfo.size();
        DeviceCreateInfo.pQueueCreateInfos    = DeviceQueueCreateInfo.data();
    }

    auto ret = Instance->vkCreateDevice( PhysicalDevice.PhysicalDevice, &DeviceCreateInfo, nullptr, &Device );
    return ret == VK_SUCCESS;
}

void CVkDevice::Destory()
{
    Instance->vkDeviceWaitIdle( Device );
    Instance->vkDestroyDevice( Device, nullptr );
}
