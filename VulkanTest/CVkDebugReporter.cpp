#include "CVkDebugReporter.h"

#include <assert.h>
#include <iostream>

VkBool32 VKAPI_CALL CVkDebugReporter::DebugReportCallbackEXT( VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location,
                                                              int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData )
{
    return static_cast<CVkDebugReporter*>( pUserData )->_DebugReportCallbackEXT( flags, objectType, object, location, messageCode, pLayerPrefix, pMessage );
}

VkBool32 CVkDebugReporter::_DebugReportCallbackEXT( VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode,
                                                    const char* pLayerPrefix, const char* pMessage )
{
    std::cout << pMessage << std::endl;
    return VK_SUCCESS;
}

void CVkDebugReporter::Init( VkInstance instace )
{
    CreateInfo = {//sType
                  VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT,
                  //pNext
                  nullptr,
                  //flags
                  VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_DEBUG_BIT_EXT,
                  //pfnCallback
                  &DebugReportCallbackEXT,
                  //pUserData
                  this};
    Instance                            = instace;
    auto vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr( instace, "vkCreateDebugReportCallbackEXT" );
    assert( vkCreateDebugReportCallbackEXT );

    vkCreateDebugReportCallbackEXT( instace, &CreateInfo, nullptr, &Handle );
}

void CVkDebugReporter::UnInit()
{
    auto vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr( Instance, "vkDestroyDebugReportCallbackEXT" );
    vkDestroyDebugReportCallbackEXT( Instance, Handle, nullptr );
    
}
