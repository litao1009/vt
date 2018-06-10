#pragma once

#include <memory>
#include <string>

class VkLoader
{
    class Imp;
    std::unique_ptr<Imp> ImpUPtr_;

public:
    VkLoader();

    ~VkLoader();

public:
    static VkLoader& GetInstance();

public:

    bool LoadLibrary( const std::string& path );

	bool LoadGlobalFunction();
};