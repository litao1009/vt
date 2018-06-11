#include "CVkBuffer.h"

bool CVkBuffer::Create()
{
    auto ret = Device->PhysicalDevice.InstanceFunctions.vkCreateBuffer( Device->DeviceHandle, &BufferCreateInfo, AllocationCallbacks, &BufferHandle );

    return ret == VK_SUCCESS;
}

void CVkBuffer::Destory()
{
    Device->PhysicalDevice.InstanceFunctions.vkDestroyBuffer( Device->DeviceHandle, BufferHandle, AllocationCallbacks );
}