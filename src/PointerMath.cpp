#include "PointerMath.h"


void* PointerMath::addBytes(void* ptr, std::size_t size_bytes) {

	return (void*)(reinterpret_cast<intptr_t>(ptr) +
	 (size_bytes / sizeof(intptr_t) + sizeof(intptr_t) +
	 	reinterpret_cast<intptr_t>(ptr) % sizeof(intptr_t)));
}
