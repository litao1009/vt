#pragma once

#include "VKHeader.h"

class CVkAllocator
{
    static void* VKAPI_CALL Allocation( void* pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope );

    static void* VKAPI_CALL Reallocation( void* pUserData, void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope );

    static void VKAPI_CALL Free( void* pUserData, void* memory );

private:
    void* _Allocation( size_t size, size_t alignment, VkSystemAllocationScope allocationScope );

    void* _Reallocation( void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope );

    void _Free( void* memory );

public:
    inline operator VkAllocationCallbacks() const
    {
        VkAllocationCallbacks result;

        result.pUserData             = (void*)this;
        result.pfnAllocation         = &Allocation;
        result.pfnReallocation       = &Reallocation;
        result.pfnFree               = &Free;
        result.pfnInternalAllocation = nullptr;
        result.pfnInternalFree       = nullptr;
    }
};