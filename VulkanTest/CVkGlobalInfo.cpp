#include "CVkGlobalInfo.h"

CVkGlobalInfo& CVkGlobalInfo::GetInstance()
{
    static CVkGlobalInfo sIns;
    return sIns;
}

void CVkGlobalInfo::QueryInstanceInfo()
{
    uint32_t count{};
    vkEnumerateInstanceLayerProperties( &count, nullptr );
    if ( count != 0 )
    {
        EnumerateInstanceLayerProperties.resize( count );
        vkEnumerateInstanceLayerProperties( &count, EnumerateInstanceLayerProperties.data() );
    }

    vkEnumerateInstanceExtensionProperties( nullptr, &count, nullptr );
    if ( count != 0 )
    {
        EnumerateInstanceExtensionProperties.resize( count );
        vkEnumerateInstanceExtensionProperties( nullptr, &count, EnumerateInstanceExtensionProperties.data() );
    }
    
    uint32_t version{};
    vkEnumerateInstanceVersion( &version );
    MajorVersion = VK_VERSION_MAJOR( version );
    MinorVersion = VK_VERSION_MINOR( version );
    PatchVersion = VK_VERSION_PATCH( version );
}
