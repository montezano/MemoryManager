#include "StackAllocator.h"

StackAllocator::~StackAllocator() {}

// StackAllocator& StackAllocator::getInstance(){
// 	if(instance){
// 		return instance;
// 	}
// 	instance = new StackAllocator();
// 	return instance;
// }

void* StackAllocator::alloc(std::size_t size_bytes) {

    if(reinterpret_cast<intptr_t>(PointerMath::addBytes(mMarker, size_bytes))
    	 > reinterpret_cast<intptr_t>(mStackTop)) {
        throw std::bad_alloc();
    }

    void* retPtr = mMarker;
    mMarker = PointerMath::addBytes(mMarker, size_bytes);
    mAllocMem = mAllocMem + size_bytes;
    return retPtr;
}



