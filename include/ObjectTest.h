#ifndef __OBJECTTEST_H__
#define __OBJECTTEST_H__

//Std includes
#include <new>

//project files
#include "StackAllocator.h"


class ObjectTest {
public:
	ObjectTest();
	// ObjectTest(int testNUmber);
	~ObjectTest();

	int getNumber1();

	void* operator new(size_t size_bytes);
	void operator delete(void* ptr);
private:
	int number1;
};

#endif //__OBJECTTEST_H__