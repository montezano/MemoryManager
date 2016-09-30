#include "PointerMath.h"


void* PointerMath::addBytes(void* ptr, std::size_t size_bytes) {
	Aligner::alignBlocks(size_bytes);
	return (void*)(reinterpret_cast<intptr_t>(ptr) + size_bytes);
}

uint64_t PointerMath::addressBytesDiff(void* ptrTop, void* ptrBottom) {
	return static_cast<uint64_t>(reinterpret_cast<intptr_t>(ptrTop) - reinterpret_cast<intptr_t>(ptrBottom));
}