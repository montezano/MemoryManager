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

TEST_F(StackAllocatorTest, ValidMemorySize) {
    ASSERT_NO_THROW(memAlloc.Allocator(sizeof(int)));
}

TEST_F(StackAllocatorTest, InvalidMemmorySize) {
    ASSERT_THROW(memAlloc.Allocator(1000000000000ul), std::bad_alloc);
}

TEST_F(StackAllocatorTest, alloc_successufully) {
    memAlloc.Allocator(sizeof(int));
    EXPECT_NO_THROW(memAlloc.alloc(sizeof(int)));
}

TEST_F(StackAllocatorTest, alloc_more_than_avaiable) {
    memAlloc.Allocator(sizeof(int));
    ASSERT_THROW(memAlloc.alloc(sizeof(long int)), std::bad_alloc);
}

TEST_F(StackAllocatorTest, alloc_object) {
    memAlloc.Allocator(200000ul);
    ASSERT_NO_THROW(memAlloc.alloc(sizeof(ObjectTest)));
}

TEST_F(StackAllocatorTest, access_allocated_object) {
    memAlloc.Allocator(200000ul);
    void* ptr = memAlloc.alloc(sizeof(ObjectTest));
    ObjectTest* obj = new (ptr) ObjectTest();

    ASSERT_EQ(obj->getNumber1(), 12);
    ASSERT_NE(obj->getNumber1(), 11);
}