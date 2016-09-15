#include "gtest.h"
#include "StackAllocator.h"
#include "ObjectTest.h"


class StackAllocatorTest : public ::testing::Test {

protected:
	virtual void SetUp() {
        memAlloc = StackAllocator();
	}

    virtual void TearDown() {
        // delete(memAlloc);
    }
    StackAllocator memAlloc;
};

TEST_F(StackAllocatorTest, allocator_valid_memmory_size) {
    ASSERT_NO_THROW(memAlloc.Allocator(sizeof(int)));
}

TEST_F(StackAllocatorTest, allocator_invalid_memmory_size) {
    ASSERT_THROW(memAlloc.Allocator(1000000000000ul), std::bad_alloc);
}

TEST_F(StackAllocatorTest, alloc_successufully) {
    memAlloc.Allocator(sizeof(int));
    EXPECT_NO_THROW(memAlloc.alloc(sizeof(int)));
}

TEST_F(StackAllocatorTest, alloc_more_than_avaiable) {
     std::cout << "int size: " << sizeof(int[10]) << std::endl;
     std::cout << "int size: " << sizeof(long int) << std::endl;
    memAlloc.Allocator(sizeof(int));
    ASSERT_THROW(memAlloc.alloc(sizeof(int[10])), std::bad_alloc);
}

TEST_F(StackAllocatorTest, alloc_object) {
    memAlloc.Allocator(200000ul);
    ASSERT_NO_THROW(memAlloc.alloc(sizeof(ObjectTest)));
}

TEST_F(StackAllocatorTest, access_single_alloc_object) {
    memAlloc.Allocator(sizeof(ObjectTest));
    void* ptr = memAlloc.alloc(sizeof(ObjectTest));
    ObjectTest* obj = new (ptr) ObjectTest();
    std::cout << memAlloc.getStackBase() << " " << memAlloc.getStackTop() << std::endl;

    ASSERT_EQ(obj->getNumber1(), 12);
}

TEST_F(StackAllocatorTest, access_array_alloc_object) {


    memAlloc.Allocator(sizeof(int[50]));
    void* ptr = memAlloc.alloc(sizeof(int[50]));
    int* array = new (ptr) int[50]();
    std::cout << "int size: " << sizeof(int[50]) << std::endl;

    std::cout << memAlloc.getStackBase() << " " << memAlloc.getStackTop() << std::endl;
    std::cout << "size of memAlloc: " << sizeof(memAlloc) << std::endl;
    for(int i = 0; i < 50; i++){
        std::cout << i << std::endl;
        array[i] = i;
    }
        // std::cout << "END OF THE INITIALIZATION" << std::endl;

    for(int i = 0; i < 50; i++){
        std::cout << i << std::endl;
        ASSERT_EQ(array[i], i);
    }
    std::cout << "END OF THE INITIALIZATION" << std::endl;
    delete(array);
        std::cout << "END OF THE INITIALIZATION" << std::endl;


    
}

TEST_F(StackAllocatorTest, access_array_alloc_object2) {


    // memAlloc.Allocator<long int>(sizeof(long int[50]));
    // void* ptr = memAlloc.alloc(50ul);
    // long int* array = new (ptr) long int[50]();
    // std::cout << "int size: " << sizeof(long int[50]) << std::endl;

    // std::cout << memAlloc.getStackBase() << " " << memAlloc.getStackTop() << std::endl;
    // std::cout << "size of memAlloc: " << sizeof(memAlloc) << std::endl;
    // for(int i = 0; i < 50; i++){
    //     // std::cout << i << std::endl;
    //     array[i] = i;
    // }
    //     // std::cout << "END OF THE INITIALIZATION" << std::endl;

    // for(int i = 0; i < 50; i++){
    //     // std::cout << i << std::endl;
    //     ASSERT_EQ(array[i], i);
    // }
    
}