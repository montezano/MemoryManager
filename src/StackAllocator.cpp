#include "StackAllocator.h"

StackAllocator::StackAllocator(){
	mStackBottom = 0;
    mStackTop = 0;
    mMarker = 0;
    mReleaseMarker = 0;
    mAllocMem = 0;
}

StackAllocator::~StackAllocator() {}

StackAllocator& StackAllocator::getInstance() {
    	static StackAllocator instance;
    	return instance;
}

void* StackAllocator::alloc(std::size_t size_bytes) {
    Aligner::alignBlocks(size_bytes);
    if(reinterpret_cast<intptr_t>(PointerMath::addBytes(mMarker, size_bytes))
    	 > reinterpret_cast<intptr_t>(mStackTop)) {
        throw std::bad_alloc();
    }

    void* retPtr = mMarker;
    mMarker = PointerMath::addBytes(mMarker, size_bytes);
    mAllocMem = mAllocMem + size_bytes;
    return retPtr;
}

void StackAllocator::markReleasableMemory() {
	mReleaseMarker = mMarker;

}

void StackAllocator::releaseMemory() {
	mAllocMem = mAllocMem - PointerMath::addressBytesDiff(mMarker, mReleaseMarker);
	Aligner::alignBlocks(mAllocMem);
	mMarker = mReleaseMarker;
}