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



TEST_F(StackAllocatorTest, alloc_data_memmory) {
    try{
        memAlloc.Allocator(sizeof(int));
        int* data = (int*)memAlloc.alloc(sizeof(int));
        EXPECT_NE(data, nullptr);
    } catch (...) {
        FAIL();
    }

}

TEST_F(StackAllocatorTest, invalid_data_size) {
    try{
        memAlloc.Allocator(sizeof(int));
        (int*)memAlloc.alloc(1ul);
        FAIL();
     } catch (std::bad_alloc& e) {
        ASSERT_TRUE(false);
    } catch (...) {
        ASSERT_TRUE(false);
    }

}


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