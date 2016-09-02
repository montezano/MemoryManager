#include "gtest.h"
#include <MemmoryAllocator.h> 


class MemmoryAllocatorTest : public ::testing::Test {

protected:
	virtual void SetUp() {
        memAlloc = MemmoryAllocator();
	}

    virtual void TearDown() {
        // delete(memAlloc);
    }
    MemmoryAllocator memAlloc;
};



TEST_F(MemmoryAllocatorTest, ValidMemorySize) {
    try{
        memAlloc.Allocator(sizeof(int));
    } catch (const std::bad_alloc& e) {
        FAIL();
    } catch (...) {
        FAIL();
    }
    EXPECT_TRUE(true);
}

TEST_F(MemmoryAllocatorTest, InvalidMemmorySize) {
    try {
        memAlloc.Allocator(100000000ul);
    } catch (std::bad_alloc& e) {
        EXPECT_EQ(e.what(),std::string("Out of range"));
    } catch (...) {
        FAIL();
    }
}

TEST_F(MemmoryAllocatorTest, Access_alocated_data) {

}