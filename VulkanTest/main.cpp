#include "VKHeader.h"
#include "CVkGlobalInfo.h"
#include "VkLoader.h"
#include "CVkInstance.h"

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
    instance.Destory();
}