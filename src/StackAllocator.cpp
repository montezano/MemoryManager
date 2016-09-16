#include "StackAllocator.h"

StackAllocator::StackAllocator() {}

StackAllocator::~StackAllocator() {}

void* StackAllocator::alloc(std::size_t size_bytes) {

    if(reinterpret_cast<intptr_t>(PointerMath::addBytes(mMarker, size_bytes))
    	 > reinterpret_cast<intptr_t>(mStackTop)) {
        throw std::bad_alloc();
    }

    mMarker = PointerMath::addBytes(mMarker, size_bytes);
    mAllocMem = mAllocMem + size_bytes;
    return mMarker;
}

template<typename T> T* StackAllocator::alloc(T myType){

	std::size_t size_bytes = sizeof(T);
	if(reinterpret_cast<intptr_t>(PointerMath::addBytes(mMarker, size_bytes))
    	 > reinterpret_cast<intptr_t>(mStackTop)) {
        throw std::bad_alloc();
    }

    mMarker = PointerMath::addBytes(mMarker, size_bytes);
    mAllocMem = mAllocMem + size_bytes;

    T* ptr = mMarker;
    return new (ptr) T();

}

