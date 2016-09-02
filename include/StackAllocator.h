#ifndef __STACKALLOCATOR__H__
#define __STACKALLOCATOR__H__

#include "MemmoryAllocator.h"

class StackAllocator : public MemmoryAllocator {
    public:
    StackAllocator();
    ~StackAllocator();

    void* alloc(std::size_t sizeBytes);

};

#endif