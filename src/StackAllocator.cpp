#include "StackAllocator.h"

StackAllocator::StackAllocator() {

}

StackAllocator::~StackAllocator() {

}

void* StackAllocator::alloc(std::size_t size_bytes) {
    if((char*)mStackBottom + size_bytes > mStackTop) {
        throw std::bad_alloc();
    }

    mStackTop = (void*)((char*)mStackTop + size_bytes);
}