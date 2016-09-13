#include "StackAllocator.h"

StackAllocator::StackAllocator() {

}

StackAllocator::~StackAllocator() {

}

void* StackAllocator::alloc(std::size_t size_bytes) {
    if(reinterpret_cast<intptr_t>(mStackBottom) + size_bytes > reinterpret_cast<intptr_t>(mStackTop)) {
        throw std::bad_alloc();
    }

    mMarker = mStackTop;
    mStackTop = (void*)(reinterpret_cast<intptr_t>(mStackTop) + size_bytes);
    mStackSize = mStackSize + size_bytes;
    return mMarker;
}