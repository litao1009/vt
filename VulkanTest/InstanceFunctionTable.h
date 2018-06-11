#pragma once

#include "VKHeader.h"

class   InstanceFunctionTable
{
public:
#define DECLARE_INSTANCE_FUNC( func ) PFN_##func func{};

    // Core 1.0 functions
    DECLARE_INSTANCE_FUNC( vkDestroyInstance )
    DECLARE_INSTANCE_FUNC( vkEnumeratePhysicalDevices )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceFeatures )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceFormatProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceImageFormatProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceSparseImageFormatProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceQueueFamilyProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceMemoryProperties )
    DECLARE_INSTANCE_FUNC( vkEnumerateDeviceLayerProperties )
    DECLARE_INSTANCE_FUNC( vkEnumerateDeviceExtensionProperties )
    DECLARE_INSTANCE_FUNC( vkCreateDevice )
    DECLARE_INSTANCE_FUNC( vkGetDeviceProcAddr )
    DECLARE_INSTANCE_FUNC( vkDestroyDevice )
    DECLARE_INSTANCE_FUNC( vkGetDeviceQueue )
    DECLARE_INSTANCE_FUNC( vkQueueSubmit )
    DECLARE_INSTANCE_FUNC( vkQueueWaitIdle )
    DECLARE_INSTANCE_FUNC( vkDeviceWaitIdle )
    DECLARE_INSTANCE_FUNC( vkAllocateMemory )
    DECLARE_INSTANCE_FUNC( vkFreeMemory )
    DECLARE_INSTANCE_FUNC( vkMapMemory )
    DECLARE_INSTANCE_FUNC( vkUnmapMemory )
    DECLARE_INSTANCE_FUNC( vkFlushMappedMemoryRanges )
    DECLARE_INSTANCE_FUNC( vkInvalidateMappedMemoryRanges )
    DECLARE_INSTANCE_FUNC( vkGetDeviceMemoryCommitment )
    DECLARE_INSTANCE_FUNC( vkGetImageSparseMemoryRequirements )
    DECLARE_INSTANCE_FUNC( vkGetImageMemoryRequirements )
    DECLARE_INSTANCE_FUNC( vkGetBufferMemoryRequirements )
    DECLARE_INSTANCE_FUNC( vkBindImageMemory )
    DECLARE_INSTANCE_FUNC( vkBindBufferMemory )
    DECLARE_INSTANCE_FUNC( vkQueueBindSparse )
    DECLARE_INSTANCE_FUNC( vkCreateFence )
    DECLARE_INSTANCE_FUNC( vkDestroyFence )
    DECLARE_INSTANCE_FUNC( vkGetFenceStatus )
    DECLARE_INSTANCE_FUNC( vkResetFences )
    DECLARE_INSTANCE_FUNC( vkWaitForFences )
    DECLARE_INSTANCE_FUNC( vkCreateSemaphore )
    DECLARE_INSTANCE_FUNC( vkDestroySemaphore )
    DECLARE_INSTANCE_FUNC( vkCreateEvent )
    DECLARE_INSTANCE_FUNC( vkDestroyEvent )
    DECLARE_INSTANCE_FUNC( vkGetEventStatus )
    DECLARE_INSTANCE_FUNC( vkSetEvent )
    DECLARE_INSTANCE_FUNC( vkResetEvent )
    DECLARE_INSTANCE_FUNC( vkCreateQueryPool )
    DECLARE_INSTANCE_FUNC( vkDestroyQueryPool )
    DECLARE_INSTANCE_FUNC( vkGetQueryPoolResults )
    DECLARE_INSTANCE_FUNC( vkCreateBuffer )
    DECLARE_INSTANCE_FUNC( vkDestroyBuffer )
    DECLARE_INSTANCE_FUNC( vkCreateBufferView )
    DECLARE_INSTANCE_FUNC( vkDestroyBufferView )
    DECLARE_INSTANCE_FUNC( vkCreateImage )
    DECLARE_INSTANCE_FUNC( vkDestroyImage )
    DECLARE_INSTANCE_FUNC( vkGetImageSubresourceLayout )
    DECLARE_INSTANCE_FUNC( vkCreateImageView )
    DECLARE_INSTANCE_FUNC( vkDestroyImageView )
    DECLARE_INSTANCE_FUNC( vkCreateShaderModule )
    DECLARE_INSTANCE_FUNC( vkDestroyShaderModule )
    DECLARE_INSTANCE_FUNC( vkCreatePipelineCache )
    DECLARE_INSTANCE_FUNC( vkDestroyPipelineCache )
    DECLARE_INSTANCE_FUNC( vkGetPipelineCacheData )
    DECLARE_INSTANCE_FUNC( vkMergePipelineCaches )
    DECLARE_INSTANCE_FUNC( vkCreateGraphicsPipelines )
    DECLARE_INSTANCE_FUNC( vkCreateComputePipelines )
    DECLARE_INSTANCE_FUNC( vkDestroyPipeline )
    DECLARE_INSTANCE_FUNC( vkCreatePipelineLayout )
    DECLARE_INSTANCE_FUNC( vkDestroyPipelineLayout )
    DECLARE_INSTANCE_FUNC( vkCreateSampler )
    DECLARE_INSTANCE_FUNC( vkDestroySampler )
    DECLARE_INSTANCE_FUNC( vkCreateDescriptorSetLayout )
    DECLARE_INSTANCE_FUNC( vkDestroyDescriptorSetLayout )
    DECLARE_INSTANCE_FUNC( vkCreateDescriptorPool )
    DECLARE_INSTANCE_FUNC( vkDestroyDescriptorPool )
    DECLARE_INSTANCE_FUNC( vkResetDescriptorPool )
    DECLARE_INSTANCE_FUNC( vkAllocateDescriptorSets )
    DECLARE_INSTANCE_FUNC( vkFreeDescriptorSets )
    DECLARE_INSTANCE_FUNC( vkUpdateDescriptorSets )
    DECLARE_INSTANCE_FUNC( vkCreateFramebuffer )
    DECLARE_INSTANCE_FUNC( vkDestroyFramebuffer )
    DECLARE_INSTANCE_FUNC( vkCreateRenderPass )
    DECLARE_INSTANCE_FUNC( vkDestroyRenderPass )
    DECLARE_INSTANCE_FUNC( vkGetRenderAreaGranularity )
    DECLARE_INSTANCE_FUNC( vkCreateCommandPool )
    DECLARE_INSTANCE_FUNC( vkDestroyCommandPool )
    DECLARE_INSTANCE_FUNC( vkResetCommandPool )
    DECLARE_INSTANCE_FUNC( vkAllocateCommandBuffers )
    DECLARE_INSTANCE_FUNC( vkFreeCommandBuffers )
    DECLARE_INSTANCE_FUNC( vkBeginCommandBuffer )
    DECLARE_INSTANCE_FUNC( vkEndCommandBuffer )
    DECLARE_INSTANCE_FUNC( vkResetCommandBuffer )
    DECLARE_INSTANCE_FUNC( vkCmdBindPipeline )
    DECLARE_INSTANCE_FUNC( vkCmdBindDescriptorSets )
    DECLARE_INSTANCE_FUNC( vkCmdBindVertexBuffers )
    DECLARE_INSTANCE_FUNC( vkCmdBindIndexBuffer )
    DECLARE_INSTANCE_FUNC( vkCmdSetViewport )
    DECLARE_INSTANCE_FUNC( vkCmdSetScissor )
    DECLARE_INSTANCE_FUNC( vkCmdSetLineWidth )
    DECLARE_INSTANCE_FUNC( vkCmdSetDepthBias )
    DECLARE_INSTANCE_FUNC( vkCmdSetBlendConstants )
    DECLARE_INSTANCE_FUNC( vkCmdSetDepthBounds )
    DECLARE_INSTANCE_FUNC( vkCmdSetStencilCompareMask )
    DECLARE_INSTANCE_FUNC( vkCmdSetStencilWriteMask )
    DECLARE_INSTANCE_FUNC( vkCmdSetStencilReference )
    DECLARE_INSTANCE_FUNC( vkCmdDraw )
    DECLARE_INSTANCE_FUNC( vkCmdDrawIndexed )
    DECLARE_INSTANCE_FUNC( vkCmdDrawIndirect )
    DECLARE_INSTANCE_FUNC( vkCmdDrawIndexedIndirect )
    DECLARE_INSTANCE_FUNC( vkCmdDispatch )
    DECLARE_INSTANCE_FUNC( vkCmdDispatchIndirect )
    DECLARE_INSTANCE_FUNC( vkCmdCopyBuffer )
    DECLARE_INSTANCE_FUNC( vkCmdCopyImage )
    DECLARE_INSTANCE_FUNC( vkCmdBlitImage )
    DECLARE_INSTANCE_FUNC( vkCmdCopyBufferToImage )
    DECLARE_INSTANCE_FUNC( vkCmdCopyImageToBuffer )
    DECLARE_INSTANCE_FUNC( vkCmdUpdateBuffer )
    DECLARE_INSTANCE_FUNC( vkCmdFillBuffer )
    DECLARE_INSTANCE_FUNC( vkCmdClearColorImage )
    DECLARE_INSTANCE_FUNC( vkCmdClearDepthStencilImage )
    DECLARE_INSTANCE_FUNC( vkCmdClearAttachments )
    DECLARE_INSTANCE_FUNC( vkCmdResolveImage )
    DECLARE_INSTANCE_FUNC( vkCmdSetEvent )
    DECLARE_INSTANCE_FUNC( vkCmdResetEvent )
    DECLARE_INSTANCE_FUNC( vkCmdWaitEvents )
    DECLARE_INSTANCE_FUNC( vkCmdPipelineBarrier )
    DECLARE_INSTANCE_FUNC( vkCmdBeginQuery )
    DECLARE_INSTANCE_FUNC( vkCmdEndQuery )
    DECLARE_INSTANCE_FUNC( vkCmdResetQueryPool )
    DECLARE_INSTANCE_FUNC( vkCmdWriteTimestamp )
    DECLARE_INSTANCE_FUNC( vkCmdCopyQueryPoolResults )
    DECLARE_INSTANCE_FUNC( vkCmdPushConstants )
    DECLARE_INSTANCE_FUNC( vkCmdBeginRenderPass )
    DECLARE_INSTANCE_FUNC( vkCmdNextSubpass )
    DECLARE_INSTANCE_FUNC( vkCmdEndRenderPass )
    DECLARE_INSTANCE_FUNC( vkCmdExecuteCommands )

    // Core 1.1 functions
    DECLARE_INSTANCE_FUNC( vkEnumeratePhysicalDeviceGroups )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceFeatures2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceProperties2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceFormatProperties2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceImageFormatProperties2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceQueueFamilyProperties2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceMemoryProperties2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceSparseImageFormatProperties2 )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceExternalBufferProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceExternalSemaphoreProperties )
    DECLARE_INSTANCE_FUNC( vkGetPhysicalDeviceExternalFenceProperties )
    DECLARE_INSTANCE_FUNC( vkBindBufferMemory2 )
    DECLARE_INSTANCE_FUNC( vkBindImageMemory2 )
    DECLARE_INSTANCE_FUNC( vkGetDeviceGroupPeerMemoryFeatures )
    DECLARE_INSTANCE_FUNC( vkCmdSetDeviceMask )
    DECLARE_INSTANCE_FUNC( vkCmdDispatchBase )
    DECLARE_INSTANCE_FUNC( vkGetImageMemoryRequirements2 )
    DECLARE_INSTANCE_FUNC( vkTrimCommandPool )
    DECLARE_INSTANCE_FUNC( vkGetDeviceQueue2 )
    DECLARE_INSTANCE_FUNC( vkCreateSamplerYcbcrConversion )
    DECLARE_INSTANCE_FUNC( vkDestroySamplerYcbcrConversion )
    DECLARE_INSTANCE_FUNC( vkGetDescriptorSetLayoutSupport )
    DECLARE_INSTANCE_FUNC( vkCreateDescriptorUpdateTemplate )
    DECLARE_INSTANCE_FUNC( vkDestroyDescriptorUpdateTemplate )
    DECLARE_INSTANCE_FUNC( vkUpdateDescriptorSetWithTemplate )
};