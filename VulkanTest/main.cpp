#define VK_NO_PROTOTYPES
#include "vulkan/vulkan.h"

#include "VKFunc.h"
#include "VkLoader.h"

#include <iostream>
#include <boost/filesystem.hpp>

class   CVkInstance
{
public:

    VkApplicationInfo   AppInfo = 
    {
        VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        "AppName",
        VK_MAKE_VERSION(1,1,0),
        "EngineName",
        VK_API_VERSION_1_1
    };

    VkInstanceCreateInfo CreateInfo = 
    {
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        0,
        &AppInfo,
        0,
        nullptr,
        0,
        nullptr
    };

    VkInstance  Instance;
    std::vector<VkLayerProperties>  VkLayerPropertyList;
    std::vector<const char*>        Layers;

public:

    bool    Create()
    {
        uint32_t count{};
        vkEnumerateInstanceLayerProperties(&count, nullptr);
        VkLayerPropertyList.resize(count);
        vkEnumerateInstanceLayerProperties(&count, VkLayerPropertyList.data());
        
        Layers.push_back("VK_LAYER_LUNARG_standard_validation");
        CreateInfo.enabledLayerCount = Layers.size();
        CreateInfo.ppEnabledLayerNames = Layers.data();

        if ( VK_SUCCESS != vkCreateInstance(&CreateInfo, nullptr, &Instance) )
        {
            std::cout << "Create Instance Failed" << std::endl;
            return false;
        }

        return true;
    }
};

int main()
{
    boost::filesystem::path loaderPath = R"(E:\repoCode\Vulkan-LoaderAndValidationLayers\)";

#ifdef _WIN32
    loaderPath /= "/build32";
#else
    loaderPath /= "/build";
#endif

    loaderPath /= "/loader";

#ifdef _DEBUG
    loaderPath /= "/Debug";
#else
    loaderPath /= "/Release";
#endif

    loaderPath /= "vulkan-1.dll";

    loaderPath = boost::filesystem::canonical(loaderPath);

    VkLoader loader;
    loader.Load(loaderPath.string());

    CVkInstance instance;
    instance.Create();
}