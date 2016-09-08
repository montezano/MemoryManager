#include "gtest.h"
#include "StackAllocator.h"


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

    // try {
    // } catch (std::bad_alloc& e) {
    //     EXPECT_EQ(e.what(),std::string("Out of range"));
    // } catch (...) {
    //     FAIL();
    // }
}

TEST_F(StackAllocatorTest, alloc_data_memmory) {
    memAlloc.Allocator(sizeof(int));
    EXPECT_NO_THROW((int*)memAlloc.alloc(sizeof(int)));
}

TEST_F(StackAllocatorTest, alloc_more_than_avaiable) {
    memAlloc.Allocator(sizeof(int));
    ASSERT_THROW((int*)memAlloc.alloc(sizeof(long int)), std::bad_alloc);
}

// TEST_F(StackAllocatorTest, access_allocated_data) {
//     try {
//         memAlloc.Allocator(20000ul);
//         int* data = 
//     }
    
// }

// TEST_F(StackAllocatorTest, )


// TEST_F(StackAllocatorTest, InvalidMemmorySize) {
//     try {
//         memAlloc.Allocator(100000000ul);
//     } catch (std::bad_alloc& e) {
//         EXPECT_EQ(e.what(),std::string("Out of range"));
//     } catch (...) {
//         FAIL();
//     }
// }

// TEST_F(StackAllocatorTest, Access_alocated_data) {

// }