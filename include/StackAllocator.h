#ifndef __STACKALLOCATOR__H__
#define __STACKALLOCATOR__H__

#include "MemmoryAllocator.h"

class StackAllocator : public MemmoryAllocator {
public:
    StackAllocator();
    ~StackAllocator();

    void* alloc(std::size_t size_bytes);

    template<typename T> T* alloc(uint16_t arraySize){
		std::size_t size_bytes = sizeof(T)*arraySize;
		if(reinterpret_cast<intptr_t>(PointerMath::addBytes(mMarker, size_bytes))
	    	 > reinterpret_cast<intptr_t>(mStackTop)) {
	        throw std::bad_alloc();
	    }

	    mMarker = PointerMath::addBytes(mMarker, size_bytes);
	    mAllocMem = mAllocMem + size_bytes;

	    T* ptr = static_cast<T*>(mMarker);
	    return new (ptr) T();
	};

};

#endif