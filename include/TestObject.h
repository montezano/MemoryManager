#ifndef __TESTOBJECT_H__
#define __TESTOBJECT_H__

//Std includes
#include <new>

//project files
#include "StackAllocator.h"


class TestObject {
public:
	TestObject();
	// TestObject(int testNUmber);
	~TestObject();

	int getNumber1();

	void* operator new(size_t size_bytes);
	void operator delete(void* ptr);
private:
	int number1;
};

#endif //__TESTOBJECT_H__