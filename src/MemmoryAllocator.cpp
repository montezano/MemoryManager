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

void MemmoryAllocator::Allocator(std::size_t size_bytes){
	mStackBottom = reinterpret_cast<void*>(::operator new(size_bytes));
    if(mStackBottom == nullptr){
        throw std::bad_alloc();
    }
    mStackSize = size_bytes;
    mStackTop = reinterpret_cast<void*>(mStackBottom + size_bytes);
    std::cout << "bottom: " << mStackBottom << " top: " << mStackTop << std::endl;
}

// void* MemmoryAllocator::alloc(std::size_t size) {
//     return nullptr;
// }