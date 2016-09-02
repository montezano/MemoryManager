#include "gtest.h"
#include <MemmoryAllocator.h> 


class MemmoryAllocatorTest : public ::testing::Test {

// protected:
// 	virtual void SetUp() {
		
// 	}

};

TEST(MemmoryAllocatorTest, InvalidMemorySize) {
    MemmoryAllocator memAlloc = MemmoryAllocator();
    memAlloc.Allocate(sizeof(int));
    
    EXPECT_TRUE(true);
}