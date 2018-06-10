#include "CVkAllocator.h"

#include <malloc.h>

void* VKAPI_CALL CVkAllocator::Allocation( void* pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope )
{
    return static_cast<CVkAllocator*>( pUserData )->_Allocation( size, alignment, allocationScope );
}

void* VKAPI_CALL CVkAllocator::Reallocation( void* pUserData, void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope )
{
    return static_cast<CVkAllocator*>( pUserData )->_Reallocation( pOriginal, size, alignment, allocationScope );
}

void VKAPI_CALL CVkAllocator::Free( void* pUserData, void* memory )
{
    static_cast<CVkAllocator*>( pUserData )->_Free( memory );
}

void* CVkAllocator::_Allocation( size_t size, size_t alignment, VkSystemAllocationScope allocationScope )
{
    return _aligned_malloc( size, alignment );
}

void* CVkAllocator::_Reallocation( void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope )
{
    return _aligned_realloc( pOriginal, size, alignment );
}

void CVkAllocator::_Free( void* memory )
{
    _aligned_free( memory );
}
