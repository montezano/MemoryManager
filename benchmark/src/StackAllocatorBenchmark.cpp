#include "hayai.hpp"
#include "StackAllocator.h"

class StackAllocatorBenchmark
	: public ::hayai::Fixture
{
	virtual void SetUp() {
		StackAllocator::getInstance().Allocator(1000000ul);
		StackAllocator::getInstance().markReleasableMemory();
	}

	virtual void TearDown() {
		StackAllocator::getInstance().cleanMemory();
	}
};

BENCHMARK(StackAllocatorBenchmark, Allocator_benchmark, 50, 10000) {
	StackAllocator::getInstance().Allocator(sizeof(int));
}


//Parametized benchmarks
BENCHMARK_P_F(StackAllocatorBenchmark, alloc, 50, 1000, (std::size_t bytes)) {
	StackAllocator::getInstance().alloc(bytes);
}

BENCHMARK_P_F(StackAllocatorBenchmark, malloc, 50, 1000, (std::size_t bytes)) {
	malloc(bytes);
}

BENCHMARK_P_INSTANCE(StackAllocatorBenchmark, alloc, (16ul));
BENCHMARK_P_INSTANCE(StackAllocatorBenchmark, alloc, (256ul));

BENCHMARK_P_INSTANCE(StackAllocatorBenchmark, malloc, (16ul));
BENCHMARK_P_INSTANCE(StackAllocatorBenchmark, malloc, (256ul));
