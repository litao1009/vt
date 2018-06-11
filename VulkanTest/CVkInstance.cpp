#include "CVkInstance.h"

#include <iostream>

bool CVkInstance::Create()
{
    //EnabledLayers.push_back( "VK_LAYER_LUNARG_standard_validation" );

    if ( !EnabledLayers.empty() )
    {
        CreateInfo.enabledLayerCount   = EnabledLayers.size();
        CreateInfo.ppEnabledLayerNames = EnabledLayers.data();
    }

    if ( !EnabledExtensions.empty() )
    {
        CreateInfo.enabledExtensionCount   = EnabledExtensions.size();
        CreateInfo.ppEnabledExtensionNames = EnabledExtensions.data();
    }

    if ( VK_SUCCESS != vkCreateInstance( &CreateInfo, AllocationCallbacks, &InstanceHandle ) )
    {
        std::cout << "Create Instance Failed" << std::endl;
        return false;
    }

#define GET_INSTANCE_FUNC( func ) FunctionTable.func = (PFN_##func)vkGetInstanceProcAddr( InstanceHandle, #func );

    GET_INSTANCE_FUNC( vkDestroyInstance )
    GET_INSTANCE_FUNC( vkEnumeratePhysicalDevices )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceFeatures )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceFormatProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceImageFormatProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceSparseImageFormatProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceQueueFamilyProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceMemoryProperties )
    GET_INSTANCE_FUNC( vkEnumerateDeviceLayerProperties )
    GET_INSTANCE_FUNC( vkEnumerateDeviceExtensionProperties )
    GET_INSTANCE_FUNC( vkCreateDevice )
    GET_INSTANCE_FUNC( vkGetDeviceProcAddr )
    GET_INSTANCE_FUNC( vkDestroyDevice )
    GET_INSTANCE_FUNC( vkGetDeviceQueue )
    GET_INSTANCE_FUNC( vkQueueSubmit )
    GET_INSTANCE_FUNC( vkQueueWaitIdle )
    GET_INSTANCE_FUNC( vkDeviceWaitIdle )
    GET_INSTANCE_FUNC( vkAllocateMemory )
    GET_INSTANCE_FUNC( vkFreeMemory )
    GET_INSTANCE_FUNC( vkMapMemory )
    GET_INSTANCE_FUNC( vkUnmapMemory )
    GET_INSTANCE_FUNC( vkFlushMappedMemoryRanges )
    GET_INSTANCE_FUNC( vkInvalidateMappedMemoryRanges )
    GET_INSTANCE_FUNC( vkGetDeviceMemoryCommitment )
    GET_INSTANCE_FUNC( vkGetImageSparseMemoryRequirements )
    GET_INSTANCE_FUNC( vkGetImageMemoryRequirements )
    GET_INSTANCE_FUNC( vkGetBufferMemoryRequirements )
    GET_INSTANCE_FUNC( vkBindImageMemory )
    GET_INSTANCE_FUNC( vkBindBufferMemory )
    GET_INSTANCE_FUNC( vkQueueBindSparse )
    GET_INSTANCE_FUNC( vkCreateFence )
    GET_INSTANCE_FUNC( vkDestroyFence )
    GET_INSTANCE_FUNC( vkGetFenceStatus )
    GET_INSTANCE_FUNC( vkResetFences )
    GET_INSTANCE_FUNC( vkWaitForFences )
    GET_INSTANCE_FUNC( vkCreateSemaphore )
    GET_INSTANCE_FUNC( vkDestroySemaphore )
    GET_INSTANCE_FUNC( vkCreateEvent )
    GET_INSTANCE_FUNC( vkDestroyEvent )
    GET_INSTANCE_FUNC( vkGetEventStatus )
    GET_INSTANCE_FUNC( vkSetEvent )
    GET_INSTANCE_FUNC( vkResetEvent )
    GET_INSTANCE_FUNC( vkCreateQueryPool )
    GET_INSTANCE_FUNC( vkDestroyQueryPool )
    GET_INSTANCE_FUNC( vkGetQueryPoolResults )
    GET_INSTANCE_FUNC( vkCreateBuffer )
    GET_INSTANCE_FUNC( vkDestroyBuffer )
    GET_INSTANCE_FUNC( vkCreateBufferView )
    GET_INSTANCE_FUNC( vkDestroyBufferView )
    GET_INSTANCE_FUNC( vkCreateImage )
    GET_INSTANCE_FUNC( vkDestroyImage )
    GET_INSTANCE_FUNC( vkGetImageSubresourceLayout )
    GET_INSTANCE_FUNC( vkCreateImageView )
    GET_INSTANCE_FUNC( vkDestroyImageView )
    GET_INSTANCE_FUNC( vkCreateShaderModule )
    GET_INSTANCE_FUNC( vkDestroyShaderModule )
    GET_INSTANCE_FUNC( vkCreatePipelineCache )
    GET_INSTANCE_FUNC( vkDestroyPipelineCache )
    GET_INSTANCE_FUNC( vkGetPipelineCacheData )
    GET_INSTANCE_FUNC( vkMergePipelineCaches )
    GET_INSTANCE_FUNC( vkCreateGraphicsPipelines )
    GET_INSTANCE_FUNC( vkCreateComputePipelines )
    GET_INSTANCE_FUNC( vkDestroyPipeline )
    GET_INSTANCE_FUNC( vkCreatePipelineLayout )
    GET_INSTANCE_FUNC( vkDestroyPipelineLayout )
    GET_INSTANCE_FUNC( vkCreateSampler )
    GET_INSTANCE_FUNC( vkDestroySampler )
    GET_INSTANCE_FUNC( vkCreateDescriptorSetLayout )
    GET_INSTANCE_FUNC( vkDestroyDescriptorSetLayout )
    GET_INSTANCE_FUNC( vkCreateDescriptorPool )
    GET_INSTANCE_FUNC( vkDestroyDescriptorPool )
    GET_INSTANCE_FUNC( vkResetDescriptorPool )
    GET_INSTANCE_FUNC( vkAllocateDescriptorSets )
    GET_INSTANCE_FUNC( vkFreeDescriptorSets )
    GET_INSTANCE_FUNC( vkUpdateDescriptorSets )
    GET_INSTANCE_FUNC( vkCreateFramebuffer )
    GET_INSTANCE_FUNC( vkDestroyFramebuffer )
    GET_INSTANCE_FUNC( vkCreateRenderPass )
    GET_INSTANCE_FUNC( vkDestroyRenderPass )
    GET_INSTANCE_FUNC( vkGetRenderAreaGranularity )
    GET_INSTANCE_FUNC( vkCreateCommandPool )
    GET_INSTANCE_FUNC( vkDestroyCommandPool )
    GET_INSTANCE_FUNC( vkResetCommandPool )
    GET_INSTANCE_FUNC( vkAllocateCommandBuffers )
    GET_INSTANCE_FUNC( vkFreeCommandBuffers )
    GET_INSTANCE_FUNC( vkBeginCommandBuffer )
    GET_INSTANCE_FUNC( vkEndCommandBuffer )
    GET_INSTANCE_FUNC( vkResetCommandBuffer )
    GET_INSTANCE_FUNC( vkCmdBindPipeline )
    GET_INSTANCE_FUNC( vkCmdBindDescriptorSets )
    GET_INSTANCE_FUNC( vkCmdBindVertexBuffers )
    GET_INSTANCE_FUNC( vkCmdBindIndexBuffer )
    GET_INSTANCE_FUNC( vkCmdSetViewport )
    GET_INSTANCE_FUNC( vkCmdSetScissor )
    GET_INSTANCE_FUNC( vkCmdSetLineWidth )
    GET_INSTANCE_FUNC( vkCmdSetDepthBias )
    GET_INSTANCE_FUNC( vkCmdSetBlendConstants )
    GET_INSTANCE_FUNC( vkCmdSetDepthBounds )
    GET_INSTANCE_FUNC( vkCmdSetStencilCompareMask )
    GET_INSTANCE_FUNC( vkCmdSetStencilWriteMask )
    GET_INSTANCE_FUNC( vkCmdSetStencilReference )
    GET_INSTANCE_FUNC( vkCmdDraw )
    GET_INSTANCE_FUNC( vkCmdDrawIndexed )
    GET_INSTANCE_FUNC( vkCmdDrawIndirect )
    GET_INSTANCE_FUNC( vkCmdDrawIndexedIndirect )
    GET_INSTANCE_FUNC( vkCmdDispatch )
    GET_INSTANCE_FUNC( vkCmdDispatchIndirect )
    GET_INSTANCE_FUNC( vkCmdCopyBuffer )
    GET_INSTANCE_FUNC( vkCmdCopyImage )
    GET_INSTANCE_FUNC( vkCmdBlitImage )
    GET_INSTANCE_FUNC( vkCmdCopyBufferToImage )
    GET_INSTANCE_FUNC( vkCmdCopyImageToBuffer )
    GET_INSTANCE_FUNC( vkCmdUpdateBuffer )
    GET_INSTANCE_FUNC( vkCmdFillBuffer )
    GET_INSTANCE_FUNC( vkCmdClearColorImage )
    GET_INSTANCE_FUNC( vkCmdClearDepthStencilImage )
    GET_INSTANCE_FUNC( vkCmdClearAttachments )
    GET_INSTANCE_FUNC( vkCmdResolveImage )
    GET_INSTANCE_FUNC( vkCmdSetEvent )
    GET_INSTANCE_FUNC( vkCmdResetEvent )
    GET_INSTANCE_FUNC( vkCmdWaitEvents )
    GET_INSTANCE_FUNC( vkCmdPipelineBarrier )
    GET_INSTANCE_FUNC( vkCmdBeginQuery )
    GET_INSTANCE_FUNC( vkCmdEndQuery )
    GET_INSTANCE_FUNC( vkCmdResetQueryPool )
    GET_INSTANCE_FUNC( vkCmdWriteTimestamp )
    GET_INSTANCE_FUNC( vkCmdCopyQueryPoolResults )
    GET_INSTANCE_FUNC( vkCmdPushConstants )
    GET_INSTANCE_FUNC( vkCmdBeginRenderPass )
    GET_INSTANCE_FUNC( vkCmdNextSubpass )
    GET_INSTANCE_FUNC( vkCmdEndRenderPass )
    GET_INSTANCE_FUNC( vkCmdExecuteCommands )

    // Core 1.1 functions
    GET_INSTANCE_FUNC( vkEnumeratePhysicalDeviceGroups )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceFeatures2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceProperties2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceFormatProperties2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceImageFormatProperties2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceQueueFamilyProperties2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceMemoryProperties2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceSparseImageFormatProperties2 )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceExternalBufferProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceExternalSemaphoreProperties )
    GET_INSTANCE_FUNC( vkGetPhysicalDeviceExternalFenceProperties )
    GET_INSTANCE_FUNC( vkBindBufferMemory2 )
    GET_INSTANCE_FUNC( vkBindImageMemory2 )
    GET_INSTANCE_FUNC( vkGetDeviceGroupPeerMemoryFeatures )
    GET_INSTANCE_FUNC( vkCmdSetDeviceMask )
    GET_INSTANCE_FUNC( vkCmdDispatchBase )
    GET_INSTANCE_FUNC( vkGetImageMemoryRequirements2 )
    GET_INSTANCE_FUNC( vkTrimCommandPool )
    GET_INSTANCE_FUNC( vkGetDeviceQueue2 )
    GET_INSTANCE_FUNC( vkCreateSamplerYcbcrConversion )
    GET_INSTANCE_FUNC( vkDestroySamplerYcbcrConversion )
    GET_INSTANCE_FUNC( vkGetDescriptorSetLayoutSupport )
    GET_INSTANCE_FUNC( vkCreateDescriptorUpdateTemplate )
    GET_INSTANCE_FUNC( vkDestroyDescriptorUpdateTemplate )
    GET_INSTANCE_FUNC( vkUpdateDescriptorSetWithTemplate )

    uint32_t count{};

    std::vector<VkPhysicalDevice> enumeratePhysicalDevices;
    FunctionTable.vkEnumeratePhysicalDevices( InstanceHandle, &count, nullptr );
    if ( count != 0 )
    {
        enumeratePhysicalDevices.resize( count );
        FunctionTable.vkEnumeratePhysicalDevices( InstanceHandle, &count, enumeratePhysicalDevices.data() );
    }

    for ( auto curPD : enumeratePhysicalDevices )
    {
        EnumeratePhysicalDevices.emplace_back();
        auto& curPDInfo = EnumeratePhysicalDevices.back();

        curPDInfo.PhysicalDeviceHandle = curPD;
        curPDInfo.InstanceFunctions    = FunctionTable;

        curPDInfo.Query();
    }

    return true;
}

bool CVkInstance::Destory()
{
    FunctionTable.vkDestroyInstance( InstanceHandle, AllocationCallbacks );
    return true;
}
