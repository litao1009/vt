#include "VkLoader.h"

#define LOADER
#include "VKFunc.h"

#include <boost/dll/import.hpp>

#include <iostream>

class   VkLoader::Imp
{
public:

    boost::dll::shared_library  Lib_;
};

VkLoader::VkLoader():ImpUPtr_(std::make_unique<Imp>())
{ }

VkLoader::~VkLoader()
{

}

bool VkLoader::Load(const std::string& path)
{
    auto& imp_ = *ImpUPtr_;

    boost::system::error_code ec;
    imp_.Lib_ = boost::dll::shared_library(path, ec);
    if ( ec )
    {
        return false;
    }

#define EXPORT_FUNC(func) func = (PFN_##func)imp_.Lib_.get<void*()>(#func);
    EXPORT_FUNC(vkGetInstanceProcAddr);
    assert(vkGetInstanceProcAddr);

#define EXPORT_VK_GLOBAL_FUNC(func) \
	        if ( !(func = (PFN_##func)vkGetInstanceProcAddr(nullptr, #func)) )\
	        {\
	            std::cout << "Could not load global level func: " << #func << "!" << std::endl;\
	            assert(0);\
	        }

    EXPORT_VK_GLOBAL_FUNC(vkCreateInstance);
    //EXPORT_VK_GLOBAL_FUNC(vkDestroyInstance);
    EXPORT_VK_GLOBAL_FUNC(vkEnumerateInstanceExtensionProperties);
    EXPORT_VK_GLOBAL_FUNC(vkEnumerateInstanceLayerProperties);
    EXPORT_VK_GLOBAL_FUNC(vkEnumerateInstanceVersion);

    return true;
}