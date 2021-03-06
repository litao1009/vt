#include "VKHeader.h"
#include "CVkGlobalInfo.h"
#include "VkLoader.h"
#include "CVkInstance.h"
#include "CVkDevice.h"
#include "CVkAllocator.h"
#include "CVkBuffer.h"
#include "CVkImage.h"
#include "CVkDebugReporter.h"

#include <iostream>

#include <boost/filesystem.hpp>

int main()
{
    boost::filesystem::path loaderPath =
        R"(E:\repoCode\Vulkan-LoaderAndValidationLayers\)";

    if ( sizeof( size_t ) == 4 )
    {
        loaderPath /= "/build32";
    }
    else
    {
        loaderPath /= "/build";
    }

    loaderPath /= "/loader";

#ifdef _DEBUG
    loaderPath /= "/Debug";
#else
    loaderPath /= "/Release";
#endif

    loaderPath /= "vulkan-1.dll";

    loaderPath = boost::filesystem::canonical( loaderPath );

    VkLoader::GetInstance().LoadLibrary( loaderPath.string() );
    VkLoader::GetInstance().LoadGlobalFunction();

    CVkGlobalInfo::GetInstance().QueryInstanceInfo();

    CVkInstance instance;
    instance.EnabledLayers.push_back( "VK_LAYER_LUNARG_standard_validation" );
    instance.EnabledExtensions.push_back( "VK_EXT_debug_report" );
    instance.Create();

    CVkDebugReporter reporter;
    reporter.Init( instance.InstanceHandle );

    CVkDevice device;
    {
        device.PhysicalDevice = instance.EnumeratePhysicalDevices[0];
        device.DeviceQueueCreateInfo.emplace_back();
        device.DeviceQueueCreateInfo[0].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        device.DeviceQueueCreateInfo[0].pNext = nullptr;
        device.DeviceQueueCreateInfo[0].flags = 0;
        for ( auto idx = 0U; idx < device.PhysicalDevice.QueueFamilyProperties.size(); ++idx )
        {
            if ( device.PhysicalDevice.QueueFamilyProperties[idx].queueFlags & VK_QUEUE_GRAPHICS_BIT )
            {
                device.DeviceQueueCreateInfo[0].queueFamilyIndex = idx;
                break;
            }
        }
        device.DeviceQueueCreateInfo[0].queueCount = 1;
        device.DeviceCreateInfo.pEnabledFeatures   = &device.PhysicalDevice.PhysicalDeviceFeatures;
    }
    device.Create();

    CVkBuffer buffer;
    buffer.BufferCreateInfo.flags = VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    buffer.BufferCreateInfo.size  = 1024 * 1024;
    buffer.Device                 = &device;

    buffer.Create();

    CVkImage image;
    image.Device = &device;
    image.Create();

    VkImageSubresource is;
    is.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    is.mipLevel   = 0;
    is.arrayLayer = 0;
    VkSubresourceLayout sl;
    instance.FunctionTable.vkGetImageSubresourceLayout( device.DeviceHandle, image.ImageHandle, &is, &sl );

    image.Destory();

    buffer.Destory();

    device.Destory();

    reporter.UnInit();
    instance.Destory();
}