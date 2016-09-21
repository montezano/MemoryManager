#include "MemoryAllocator.h"
#include <iostream>

MemoryAllocator::MemoryAllocator(){}

MemoryAllocator::~MemoryAllocator(){}

void MemoryAllocator::cleanMemory() {
	mStackTop = mStackBottom;
	mAllocMem = 0;
}

void* MemoryAllocator::getStackBase() {return mStackBottom;}

void* MemoryAllocator::getStackTop() {return mStackTop;}

void* MemoryAllocator::getMarker() {return mMarker;}

std::size_t MemoryAllocator::getStackSize() {return mAllocMem;}

void MemoryAllocator::Allocator(std::size_t size_bytes){
	mAllocMem = size_bytes;
	Aligner::alignBlocks(&mAllocMem);

	mStackBottom = (void*)(::operator new(size_bytes));
    if(mStackBottom == nullptr){
        throw std::bad_alloc();
    }
    
    mMarker = mStackBottom;
    mStackTop = PointerMath::addBytes(mStackBottom, size_bytes);
}