#include "MemmoryAllocator.h"
#include <exception>

MemmoryAllocator::MemmoryAllocator(){

}

MemmoryAllocator::~MemmoryAllocator(){

}

void MemmoryAllocator::Allocator(std::size_t size){
    mStackBottom = (void*) ::operator new(size);
    if(mStackBottom == nullptr){
        throw std::bad_alloc();
    }
    mStackSize = size;
    mStackTop = (void*)((char*)mStackBottom + size);
}