#include "ObjectTest.h"

ObjectTest::ObjectTest(){
	number1 = 12;
}

// ObjectTest::ObjectTest(int testNumber) {
// 	number1 = testNumber;
// }

ObjectTest::~ObjectTest(){
	
}

int ObjectTest::getNumber1() {
	return number1;
}

void* ObjectTest::operator new(size_t size_bytes) {
	    std::cout << sizeof(ObjectTest) << " " << StackAllocator::getInstance().getStackSize() << std::endl;

	return StackAllocator::getInstance().alloc<ObjectTest>();
}

void ObjectTest::operator delete(void* ptr){

}