#include "MemmoryAllocator.h"
#include <iostream>

MemmoryAllocator::MemmoryAllocator(){}

MemmoryAllocator::~MemmoryAllocator(){}

// void MemmoryAllocator::operator delete(void* ptr) {
// 	ptr = nullptr;
// }

void* MemmoryAllocator::getStackBase() {return mStackBottom;}

void* MemmoryAllocator::getStackTop() {return mStackTop;}

void* MemmoryAllocator::getMarker() {return mMarker;}

std::size_t MemmoryAllocator::getStackSize() {return mAllocMem;}

void MemmoryAllocator::Allocator(std::size_t size_bytes){
	mAllocMem = size_bytes;
	Aligner::alignBlocks(&mAllocMem);

	mStackBottom = (void*)(::operator new(size_bytes));
    if(mStackBottom == nullptr){
        throw std::bad_alloc();
    }
    
    mMarker = mStackBottom;
    mStackTop = PointerMath::addBytes(mStackBottom, size_bytes);
}