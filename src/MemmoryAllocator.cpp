#include "MemmoryAllocator.h"

MemmoryAllocator::MemmoryAllocator(){

}

MemmoryAllocator::~MemmoryAllocator(){

}

void MemmoryAllocator::Allocate(std::size_t size){
    mStackBottom = (void*) ::operator new(size);
    mStackSize = size;
    mStackTop = (void*)((int*)mStackBottom + size);
}