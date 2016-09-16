#include "MemmoryAllocator.h"

MemmoryAllocator::MemmoryAllocator(){}

MemmoryAllocator::~MemmoryAllocator(){}

// void* MemmoryAllocator::operator new(std::size_t size_bytes){

// }

// void MemmoryAllocator::operator delete(void* ptr){
// 	delete (mStackBottom);
// }

void* MemmoryAllocator::getStackBase() {return mStackBottom;}

void* MemmoryAllocator::getStackTop() {return mStackTop;}

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

// template<class T> void MemmoryAllocator::Allocator(std::size_t size_bytes) {
// 	mStackBottom = (void*)(::operator new(size_bytes));
//     if(mStackBottom == nullptr){
//         throw std::bad_alloc();
//     }
//     mAllocMem = size_bytes;
//     mStackTop = (void*)(reinterpret_cast<T*>(mStackBottom) + size_bytes);
// }

// void* MemmoryAllocator::alloc(std::size_t size) {
//     return nullptr;
// }