#include "VKHeader.h"
#include "CVkGlobalInfo.h"
#include "VkLoader.h"
#include "CVkInstance.h"
#include "CVkDevice.h"
#include "CVkAllocator.h"

#include <iostream>

#include <boost/filesystem.hpp>

int main()
{
    boost::filesystem::path loaderPath =
        R"(E:\Repo\Vulkan\Vulkan-LoaderAndValidationLayers\)";

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
    instance.Create();

    CVkDevice device;
    {
        device.Instance       = &instance;
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


    device.Destory();
    instance.Destory();
}