#pragma once

#include <memory>
#include <string>

class   VkLoader
{
    class   Imp;
    std::unique_ptr<Imp>    ImpUPtr_;
    
public:

    VkLoader();

    ~VkLoader();

public:

    bool    Load(const std::string& path);
};