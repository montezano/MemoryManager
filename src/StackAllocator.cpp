#include "StackAllocator.h"

StackAllocator::StackAllocator() {

}

StackAllocator::~StackAllocator() {

}

void* StackAllocator::alloc(std::size_t sizeBytes) {
    if((char*)mStackBottom + sizeBytes > mStackTop) {
        throw std::bad_alloc();
    }

    mStackTop = (void*)((char*)mStackTop + sizeBytes);
}