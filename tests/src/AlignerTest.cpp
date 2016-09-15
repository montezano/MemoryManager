#include "gtest.h"
#include "Aligner.h"


class AlignerTest : public ::testing::Test {

};





TEST_F(AlignerTest, align_aligned_bytes) {
	size_t aligned_bytes = sizeof(intptr_t);
	Aligner::alignBlocks(&aligned_bytes);
	ASSERT_EQ(aligned_bytes%sizeof(intptr_t), (unsigned int)0);
}

TEST_F(AlignerTest, align_not_aligned_bytes) {
	size_t aligned_bytes = sizeof(intptr_t) +1;
	Aligner::alignBlocks(&aligned_bytes);
	ASSERT_EQ(aligned_bytes%sizeof(intptr_t), (unsigned int)0);
}