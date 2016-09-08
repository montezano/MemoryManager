#ifndef __MEMMORYALLOCATOR__H__
#define __MEMMORYALLOCATOR__H__

//Std includes
#include <new>
#include <cstddef>
#include <exception>
#include <iostream>


class MemmoryAllocator{
public:
    MemmoryAllocator();
    ~MemmoryAllocator();

    // void* operator new(std::size_t size_bytes);
    // void operator delete(void* ptr);
    
    virtual void Allocator(std::size_t size_bytes);
    virtual void* alloc(std::size_t size_bytes) = 0;

    protected:

    void* mStackBottom;
    void* mStackTop;
    std::size_t mStackSize;
};

#endif