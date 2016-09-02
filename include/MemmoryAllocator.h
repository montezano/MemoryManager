#ifndef __MEMMORYALLOCATOR__H__
#define __MEMMORYALLOCATOR__H__

#include <new>
#include <cstddef>

class MemmoryAllocator{
public:
    MemmoryAllocator();
    ~MemmoryAllocator();
    
    void Allocate(std::size_t size);

    private:

    void* mStackBottom;
    void*  mStackTop;
    std::size_t mStackSize;
};

#endif