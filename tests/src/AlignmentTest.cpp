#include "gtest.h"

#include "Aligner.h"

class AlignmentTest : public ::testing::Test {

};

TEST(AlignmentTest, aligned_blocks) {
	std::size_t alignment = sizeof(intptr_t);
	Aligner::alignBlocks(alignment);
    
    EXPECT_EQ(alignment, sizeof(intptr_t));

    alignment = sizeof(intptr_t) + 1;
   	Aligner::alignBlocks(alignment);


    EXPECT_EQ(alignment, sizeof(intptr_t)*2);
}

TEST(AlignmentTest, unaligned_blocks) {
	std::size_t alignment = sizeof(intptr_t) - 1;
	Aligner::alignBlocks(alignment);
    
    EXPECT_EQ(alignment, sizeof(intptr_t));
}