#ifndef __OBJECTTEST_H__
#define __OBJECTTEST_H__

//Std includes
#include <new>

//project files
#include "MemoryAllocator.h"


class ObjectTest {
public:
	ObjectTest();
	~ObjectTest();

	int getNumber1();

	// void* operator new(std::size_t size_bytes, MemoryAllocator& allocator);
	// void operator delete(void* ptr);
private:
	int number1;
};

#endif //__OBJECTTEST_H__