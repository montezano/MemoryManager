#ifndef __OBJECTTEST_H__
#define __OBJECTTEST_H__

//Std includes
#include <new>

//project files
#include "MemmoryAllocator.h"


class ObjectTest {
	ObjectTest();
	~ObjectTest();

	void* operator new(std::size_t size_bytes, MemmoryAllocator& allocator);
	void operator delete(void* ptr);
};

#endif //__OBJECTTEST_H__