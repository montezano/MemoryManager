#include "TestObject.h"

TestObject::TestObject(){
	number1 = 12;
}

// TestObject::TestObject(int testNumber) {
// 	number1 = testNumber;
// }

TestObject::~TestObject(){
	
}

int TestObject::getNumber1() {
	return number1;
}

void* TestObject::operator new(size_t size_bytes) {
	return StackAllocator::getInstance().alloc<TestObject>();
}

void TestObject::operator delete(void* ptr){
	
}