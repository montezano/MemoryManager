#include "PointerMath.h"


void* PointerMath::addBytes(void* ptr, std::size_t size_bytes) {
	Aligner::alignBlocks(&size_bytes);
	return (void*)(reinterpret_cast<intptr_t>(ptr) + size_bytes + sizeof(intptr_t));
}
