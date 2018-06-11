#include "CVkPhysicalDevice.h"

#include "CVkInstance.h"

void CVkPhysicalDevice::Query()
{
    uint32_t count{};

    InstanceFunctions.vkGetPhysicalDeviceProperties( PhysicalDeviceHandle, &PhysicalDeviceProperties );
    InstanceFunctions.vkGetPhysicalDeviceFeatures( PhysicalDeviceHandle, &PhysicalDeviceFeatures );
    InstanceFunctions.vkGetPhysicalDeviceMemoryProperties( PhysicalDeviceHandle, &PhysicalDeviceMemoryProperties );

    count = 0;
    InstanceFunctions.vkGetPhysicalDeviceQueueFamilyProperties( PhysicalDeviceHandle, &count, nullptr );
    if ( count != 0 )
    {
        QueueFamilyProperties.resize( count );
        InstanceFunctions.vkGetPhysicalDeviceQueueFamilyProperties( PhysicalDeviceHandle, &count, QueueFamilyProperties.data() );
    }

    count = 0;
    InstanceFunctions.vkEnumerateDeviceLayerProperties( PhysicalDeviceHandle, &count, nullptr );
    if ( count != 0 )
    {
        PhysicalDeviceLayerProperties.resize( count );
        InstanceFunctions.vkEnumerateDeviceLayerProperties( PhysicalDeviceHandle, &count, PhysicalDeviceLayerProperties.data() );
    }

    count = 0;
    InstanceFunctions.vkEnumerateDeviceExtensionProperties( PhysicalDeviceHandle, nullptr, &count, nullptr );
    if ( count != 0 )
    {
        PhysicalDeviceExtensionProperties.resize( count );
        InstanceFunctions.vkEnumerateDeviceExtensionProperties( PhysicalDeviceHandle, nullptr, &count, PhysicalDeviceExtensionProperties.data() );
    }

    VkFormatProperties vfp;
#define QUERY_FORMAT( fmt )                                                                             \
    InstanceFunctions.vkGetPhysicalDeviceFormatProperties( PhysicalDeviceHandle, (VkFormat)fmt, &vfp ); \
    if ( vfp.bufferFeatures != 0 || vfp.linearTilingFeatures != 0 || vfp.optimalTilingFeatures != 0 )   \
    {                                                                                                   \
        FormatProperties.emplace( (VkFormat)fmt, vfp );                                                 \
    }

    for ( auto fmtIdx = VK_FORMAT_BEGIN_RANGE + 1; fmtIdx <= VK_FORMAT_END_RANGE; ++fmtIdx )
    {
        QUERY_FORMAT( fmtIdx )
    }

    QUERY_FORMAT( VK_FORMAT_G8B8G8R8_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_B8G8R8G8_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM )
    QUERY_FORMAT( VK_FORMAT_G8_B8R8_2PLANE_420_UNORM )
    QUERY_FORMAT( VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_G8_B8R8_2PLANE_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM )
    QUERY_FORMAT( VK_FORMAT_R10X6_UNORM_PACK16 )
    QUERY_FORMAT( VK_FORMAT_R10X6G10X6_UNORM_2PACK16 )
    QUERY_FORMAT( VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 )
    QUERY_FORMAT( VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 )
    QUERY_FORMAT( VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 )
    QUERY_FORMAT( VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_R12X4_UNORM_PACK16 )
    QUERY_FORMAT( VK_FORMAT_R12X4G12X4_UNORM_2PACK16 )
    QUERY_FORMAT( VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 )
    QUERY_FORMAT( VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 )
    QUERY_FORMAT( VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 )
    QUERY_FORMAT( VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 )
    QUERY_FORMAT( VK_FORMAT_G16B16G16R16_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_B16G16R16G16_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM )
    QUERY_FORMAT( VK_FORMAT_G16_B16R16_2PLANE_420_UNORM )
    QUERY_FORMAT( VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_G16_B16R16_2PLANE_422_UNORM )
    QUERY_FORMAT( VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM )
    QUERY_FORMAT( VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG )
    QUERY_FORMAT( VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG )
}
