#pragma once
#include "VKHeader.h"
#include "CVkDevice.h"

class CVkBuffer
{
public:
    VkBuffer BufferHandle = VK_NULL_HANDLE;

public:
    VkBufferCreateInfo BufferCreateInfo = {
        //sType
        VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        //pNext
        nullptr,
        //flags
        0,
        //size
        0,
        //usage,VK_BUFFER_USAGE_XXX
        0,
        //sharingMode
        VK_SHARING_MODE_EXCLUSIVE,
        //queueFamilyIndexCount
        0,
        //pQueueFamilyIndices
        nullptr};

    CVkDevice* Device{};
    VkAllocationCallbacks* AllocationCallbacks{};

public:
    bool Create();

    void Destory();
};