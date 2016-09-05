#ifndef __MEMMORYALLOCATOR__H__
#define __MEMMORYALLOCATOR__H__

#include <new>
#include <cstddef>

class MemmoryAllocator{
public:
    MemmoryAllocator();
    ~MemmoryAllocator();
    
    virtual void Allocator(std::size_t sizeSize);
    virtual void* alloc(std::size_t sizeBytes) = 0;

    protected:

    void* mStackBottom;
    void* mStackTop;
    std::size_t mStackSize;
};

#endif