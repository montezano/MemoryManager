#include "gtest.h"
#include "StackAllocator.h"
#include "ObjectTest.h"
#include "PointerMath.h"


class StackAllocatorTest : public ::testing::Test {

// protected:
// 	virtual void SetUp() {
//         memAlloc = StackAllocator();
// 	}

//     virtual void TearDown() {
//     }
//     StackAllocator memAlloc;
//     int* array;
// };

// TEST_F(StackAllocatorTest, allocator_valid_memmory_size) {
//     ASSERT_NO_THROW(memAlloc.Allocator(sizeof(int)));
// }

// TEST_F(StackAllocatorTest, allocator_invalid_memmory_size) {
//     ASSERT_THROW(memAlloc.Allocator(1000000000000ul), std::bad_alloc);
// }

// TEST_F(StackAllocatorTest, allocate_exact_size) {
//     memAlloc.Allocator(sizeof(int[10]));
//     ASSERT_EQ(sizeof(int[10]), PointerMath::addressBytesDiff(memAlloc.getStackTop(), memAlloc.getStackBase()));
// }

// TEST_F(StackAllocatorTest, alloc_successufully) {
//     memAlloc.Allocator(sizeof(int));
//     EXPECT_NO_THROW(memAlloc.alloc(sizeof(int)));
// }

// TEST_F(StackAllocatorTest, template_alloc_successufully) {
//     memAlloc.Allocator(sizeof(int));
//     EXPECT_NO_THROW(memAlloc.alloc<int>(0));
// }

// TEST_F(StackAllocatorTest, alloc_more_than_avaiable) {
//     memAlloc.Allocator(sizeof(int));
//     ASSERT_THROW(memAlloc.alloc(sizeof(int[10])), std::bad_alloc);
// }

// TEST_F(StackAllocatorTest, template_alloc_more_than_avaiable) {
//     memAlloc.Allocator(sizeof(int));
//     ASSERT_THROW(memAlloc.alloc<int>(10), std::bad_alloc);
// }

// TEST_F(StackAllocatorTest, alloc_object) {
//     memAlloc.Allocator(200000ul);
//     ASSERT_NO_THROW(memAlloc.alloc(sizeof(ObjectTest)));
// }

// TEST_F(StackAllocatorTest, template_alloc_object) {
//     memAlloc.Allocator(200000ul);
//     ASSERT_NO_THROW(memAlloc.alloc<ObjectTest>());
// }

// TEST_F(StackAllocatorTest, access_single_alloc_object) {
//     memAlloc.Allocator(sizeof(ObjectTest));
//     void* ptr = memAlloc.alloc(sizeof(ObjectTest));
//     ObjectTest* obj = new (ptr) ObjectTest();

//     ASSERT_EQ(obj->getNumber1(), 12);
// }

// TEST_F(StackAllocatorTest, template_access_single_alloc_object) {
//     memAlloc.Allocator(sizeof(ObjectTest));
//     ObjectTest* ptr = memAlloc.alloc<ObjectTest>();

//     ASSERT_EQ(ptr->getNumber1(), 12);
// }

// TEST_F(StackAllocatorTest, alloc_array_avaiable_mem) {

//     memAlloc.Allocator(sizeof(int[50]));

//     ASSERT_NO_THROW(memAlloc.alloc(sizeof(int[50])));
// }

// TEST_F(StackAllocatorTest, template_alloc_array_avaiable_mem) {

//     memAlloc.Allocator(sizeof(int[50]));

//     ASSERT_NO_THROW(memAlloc.alloc<int>(50));
// }

// TEST_F(StackAllocatorTest, alloc_array_unavaiable_mem) {

//     memAlloc.Allocator(sizeof(int[50]));

//     ASSERT_THROW(memAlloc.alloc(sizeof(int[51])), std::bad_alloc);
// }

// TEST_F(StackAllocatorTest, access_array_alloc) {

//     memAlloc.Allocator(sizeof(int[51]));
    
//     array = new (memAlloc.alloc(sizeof(int[50]))) int[50]();

//     for(int i = 0; i < 50; i++){
//         array[i] = i;
//     }

//     for(int i = 0; i < 50; i++){
//         ASSERT_EQ(array[i], i);
//     }
// }

// TEST_F(StackAllocatorTest, template_access_array_alloc_object) {

//     memAlloc.Allocator(sizeof(int[50]));

//     array = memAlloc.alloc<int>(50);
//     // int* array = new (ptr) int[50]();

//     for(int i = 0; i < 50; i++){
//         array[i] = i;
//     }

//     for(int i = 0; i < 50; i++){
//         // std::cout << i << std::endl;
//         ASSERT_EQ(array[i], i);
//     }
};