#ifndef __STACKALLOCATOR__H__
#define __STACKALLOCATOR__H__

#include "MemmoryAllocator.h"

class StackAllocator : public MemmoryAllocator {
public:

    ~StackAllocator();

    void* alloc(std::size_t size_bytes);

    static StackAllocator& getInstance(){
    	static StackAllocator instance;
    	return instance;
    }

public:
	
    StackAllocator(StackAllocator const&) = delete;
    void operator=(StackAllocator const&) = delete;


    template<typename T> T* alloc(uint16_t arraySize = 1){
		std::size_t size_bytes = sizeof(T)*arraySize;
		if(reinterpret_cast<intptr_t>(PointerMath::addBytes(mMarker, size_bytes))
	    	 > reinterpret_cast<intptr_t>(mStackTop)) {
	        throw std::bad_alloc();
	    }

	    void* retPtr = mMarker;
	    mMarker = PointerMath::addBytes(mMarker, size_bytes);
	    mAllocMem = mAllocMem + size_bytes;

	    T* ptr = static_cast<T*>(retPtr);
	    return new (ptr) T[arraySize]();
	};

private:
	StackAllocator();

};

#endif
