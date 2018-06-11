#include "CVkImage.h"

bool CVkImage::Create()
{
    auto ret = Device->PhysicalDevice.InstanceFunctions.vkCreateImage( Device->DeviceHandle, &ImageCreateInfo, AllocationCallbacks, &ImageHandle );

    return ret == VK_SUCCESS;
}

void CVkImage::Destory()
{
    Device->PhysicalDevice.InstanceFunctions.vkDestroyImage( Device->DeviceHandle, ImageHandle, AllocationCallbacks );
}