#include "TestObject2.h"

TestObject2::TestObject2(){
	number1 = 12;
}

// TestObject::TestObject(int testNumber) {
// 	number1 = testNumber;
// }

TestObject2::~TestObject2(){
	
}

int TestObject2::getNumber1() {
	return number1;
}

// void* TestObject::operator new(size_t size_bytes) {
// 	return StackAllocator::getInstance().alloc<TestObject>();
// }

// void TestObject::operator delete(void* ptr){

// }