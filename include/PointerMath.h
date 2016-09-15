#ifndef __POINTERMATH_H__
#define __POINTERMATH_H__

#include <cstddef>
#include <cstdint>

#include "Aligner.h"


class PointerMath{
public:
	static void* addBytes(void* ptr, std::size_t size_bytes);	
	
};


#endif //__POINTERMATH_H__