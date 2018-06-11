#pragma once
#include "VKHeader.h"
#include "CVkDevice.h"

class CVkImage
{
public:
    VkImage ImageHandle = VK_NULL_HANDLE;

public:
    VkImageCreateInfo ImageCreateInfo = {
        //sType
        VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        //pNext
        nullptr,
        //flags
        0,
        //imageType
        VK_IMAGE_TYPE_2D,
        //format
        VK_FORMAT_R8G8B8A8_UNORM,
        //extent
        {1024,1024,1},
        //mipLevels
        1,
        //arrayLayers
        1,
        //samples
        VK_SAMPLE_COUNT_1_BIT,
        //tiling
        VK_IMAGE_TILING_LINEAR,
        //usage
        VK_IMAGE_USAGE_SAMPLED_BIT,
        //sharingMode
        VK_SHARING_MODE_EXCLUSIVE,
        //queueFamilyIndexCount
        0,
        //pQueueFamilyIndices
        nullptr,
        //initialLayout
        VK_IMAGE_LAYOUT_UNDEFINED
    };

    CVkDevice* Device{};
    VkAllocationCallbacks* AllocationCallbacks{};

public:
    bool Create();

    void Destory();
};