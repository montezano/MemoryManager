#ifndef __TESTOBJECT2_H__
#define __TESTOBJECT2_H__

//Std includes
#include <new>

//project files
#include "StackAllocator.h"


class TestObject2 {
public:
	TestObject2();
	// TestObject(int testNUmber);
	~TestObject2();

	int getNumber1();

	// void* operator new(size_t size_bytes);
	// void operator delete(void* ptr);
private:
	int number1;
};

#endif //__OBJECTTEST_H__