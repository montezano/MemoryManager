#include "ObjectTest.h"

ObjectTest::ObjectTest(){
	number1 = 12;
}

ObjectTest::~ObjectTest(){
	
}

int ObjectTest::getNumber1() {
	return number1;
}

// void* ObjectTest::operator new(std::size_t size_bytes, MemmoryAllocator& allocator) {
// 	allocator.alloc
// }

// void ObjectTest::operator delete(void* ptr){

// }