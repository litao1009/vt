#include "CVkDevice.h"

bool CVkDevice::Create()
{
    if ( !DeviceQueueCreateInfo.empty() )
    {
        DeviceCreateInfo.queueCreateInfoCount = DeviceQueueCreateInfo.size();
        DeviceCreateInfo.pQueueCreateInfos    = DeviceQueueCreateInfo.data();
    }

    auto ret = PhysicalDevice.InstanceFunctions.vkCreateDevice( PhysicalDevice.PhysicalDeviceHandle, &DeviceCreateInfo, AllocationCallbacks, &DeviceHandle );
    return ret == VK_SUCCESS;
}

void CVkDevice::Destory()
{
    PhysicalDevice.InstanceFunctions.vkDeviceWaitIdle( DeviceHandle );
    PhysicalDevice.InstanceFunctions.vkDestroyDevice( DeviceHandle, AllocationCallbacks );
}
