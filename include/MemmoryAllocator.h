#ifndef __MEMMORYALLOCATOR__H__
#define __MEMMORYALLOCATOR__H__

//Std includes
#include <new>
#include <cstddef>
#include <exception>
#include <iostream>
#include <assert.h>

#include "PointerMath.h"
#include "Aligner.h"


class MemmoryAllocator{
public:
    MemmoryAllocator();
    ~MemmoryAllocator();

    // void* operator new(std::size_t size_bytes);
    // void operator delete(void* ptr);
    
    virtual void Allocator(std::size_t size_bytes);
    
    
    virtual void* alloc(std::size_t size_bytes) = 0;

    void* getStackBase();
    void* getStackTop();
    std::size_t getStackSize();

protected:

    
    void* mStackBottom;
    void* mStackTop;
    void* mMarker;
    std::size_t mAllocMem;
};

#endif //__MEMMORYALLOCATOR__H__