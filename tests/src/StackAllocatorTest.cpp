#include "gtest.h"
#include "StackAllocator.h"
#include "TestObject.h"
#include "PointerMath.h"


class StackAllocatorTest : public ::testing::Test {

protected:
	virtual void SetUp() {
        
	}

    virtual void TearDown() {
        StackAllocator::getInstance().cleanMemory();
    }
    // StackAllocator memAlloc;
    int* array;
};

TEST_F(StackAllocatorTest, allocator_valid_memmory_size) {
    ASSERT_NO_THROW(StackAllocator::getInstance().Allocator(sizeof(int)));
}

TEST_F(StackAllocatorTest, allocator_invalid_memmory_size) {
    ASSERT_THROW(StackAllocator::getInstance().Allocator(1000000000000ul), std::bad_alloc);
}

TEST_F(StackAllocatorTest, allocate_exact_size) {
    StackAllocator::getInstance().Allocator(sizeof(int[10]));
    ASSERT_EQ(sizeof(int[10]), PointerMath::addressBytesDiff(StackAllocator::getInstance().getStackTop(), StackAllocator::getInstance().getStackBase()));
}

TEST_F(StackAllocatorTest, alloc_successufully) {
    StackAllocator::getInstance().Allocator(sizeof(int));
    EXPECT_NO_THROW(StackAllocator::getInstance().alloc(sizeof(int)));
}

TEST_F(StackAllocatorTest, template_alloc_successufully) {
    StackAllocator::getInstance().Allocator(sizeof(int));
    EXPECT_NO_THROW(StackAllocator::getInstance().alloc<int>(0));
}

TEST_F(StackAllocatorTest, alloc_more_than_avaiable) {
    StackAllocator::getInstance().Allocator(sizeof(int));
    ASSERT_THROW(StackAllocator::getInstance().alloc(sizeof(int[10])), std::bad_alloc);
}

TEST_F(StackAllocatorTest, template_alloc_more_than_avaiable) {
    StackAllocator::getInstance().Allocator(sizeof(int));
    ASSERT_THROW(StackAllocator::getInstance().alloc<int>(10), std::bad_alloc);
}

TEST_F(StackAllocatorTest, alloc_object) {
    StackAllocator::getInstance().Allocator(200000ul);
    ASSERT_NO_THROW(StackAllocator::getInstance().alloc(sizeof(TestObject)));
}

TEST_F(StackAllocatorTest, template_alloc_object) {
    StackAllocator::getInstance().Allocator(200000ul);
    ASSERT_NO_THROW(StackAllocator::getInstance().alloc<TestObject>());
}

TEST_F(StackAllocatorTest, access_single_alloc_object) {
    StackAllocator::getInstance().Allocator(sizeof(TestObject));
    TestObject* obj = new TestObject();
    ASSERT_EQ(obj->getNumber1(), 12);
}

TEST_F(StackAllocatorTest, template_access_single_alloc_object) {
    StackAllocator::getInstance().Allocator(sizeof(TestObject));
    TestObject* ptr = StackAllocator::getInstance().alloc<TestObject>();

    ASSERT_EQ(ptr->getNumber1(), 12);
}

TEST_F(StackAllocatorTest, alloc_array_avaiable_mem) {

    StackAllocator::getInstance().Allocator(sizeof(int[50]));

    ASSERT_NO_THROW(StackAllocator::getInstance().alloc(sizeof(int[50])));
}

TEST_F(StackAllocatorTest, template_alloc_array_avaiable_mem) {

    StackAllocator::getInstance().Allocator(sizeof(int[50]));

    ASSERT_NO_THROW(StackAllocator::getInstance().alloc<int>(50));
}

TEST_F(StackAllocatorTest, alloc_array_unavaiable_mem) {

    StackAllocator::getInstance().Allocator(sizeof(int[50]));

    ASSERT_THROW(StackAllocator::getInstance().alloc(sizeof(int[51])), std::bad_alloc);
}

TEST_F(StackAllocatorTest, access_array_alloc) {

    StackAllocator::getInstance().Allocator(sizeof(int[51]));
    
    array = new (StackAllocator::getInstance().alloc(sizeof(int[50]))) int[50]();

    for(int i = 0; i < 50; i++){
        array[i] = i;
    }

    for(int i = 0; i < 50; i++){
        ASSERT_EQ(array[i], i);
    }
}

TEST_F(StackAllocatorTest, template_access_array_alloc_object) {

    StackAllocator::getInstance().Allocator(sizeof(int[50]));

    array = StackAllocator::getInstance().alloc<int>(50);

    for(int i = 0; i < 50; i++){
        array[i] = i;
    }

    for(int i = 0; i < 50; i++){
        ASSERT_EQ(array[i], i);
    }
}

TEST_F(StackAllocatorTest, clean_memory) {
    StackAllocator::getInstance().Allocator(sizeof(int[100]));
    StackAllocator::getInstance().cleanMemory();
    ASSERT_THROW( StackAllocator::getInstance().alloc<int>(), std::bad_alloc);
}

TEST_F(StackAllocatorTest, transparent_alloc) {
    StackAllocator::getInstance().Allocator(sizeof(TestObject));

    ASSERT_NO_THROW(new TestObject());
}

TEST_F(StackAllocatorTest, release_memory) {
    StackAllocator::getInstance().Allocator(sizeof(int[15]));
    StackAllocator::getInstance().alloc<int>(10);
    StackAllocator::getInstance().markReleasableMemory();
    StackAllocator::getInstance().alloc<int>(5);
    ASSERT_EQ(sizeof(int[15]), StackAllocator::getInstance().getStackSize());
    ASSERT_THROW(StackAllocator::getInstance().alloc<int>(), std::bad_alloc);
    StackAllocator::getInstance().releaseMemory();
    ASSERT_EQ(sizeof(int[10]), StackAllocator::getInstance().getStackSize());
    ASSERT_NO_THROW(StackAllocator::getInstance().alloc<int>());
}