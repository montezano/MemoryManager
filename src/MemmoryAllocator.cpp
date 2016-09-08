#include "MemmoryAllocator.h"

MemmoryAllocator::MemmoryAllocator(){

}

MemmoryAllocator::~MemmoryAllocator(){

}

// void* MemmoryAllocator::operator new(std::size_t size_bytes){

// }

// void MemmoryAllocator::operator delete(void* ptr){
// 	delete (mStackBottom);
// }

void* MemmoryAllocator::getStackBase() {return mStackBottom;}

void* MemmoryAllocator::getStackTop() {return mStackTop;}

std::size_t MemmoryAllocator::getStackSize() {return mStackSize;}

void MemmoryAllocator::Allocator(std::size_t size_bytes){
	mStackBottom = reinterpret_cast<void*>(::operator new(size_bytes));
    if(mStackBottom == nullptr){
        throw std::bad_alloc();
    }
    mStackSize = size_bytes;
    mStackTop = reinterpret_cast<void*>(static_cast<char*>(mStackBottom) + size_bytes);
}

// void* MemmoryAllocator::alloc(std::size_t size) {
//     return nullptr;
// }