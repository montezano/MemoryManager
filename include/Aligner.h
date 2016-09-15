#ifndef __ALIGNER_H__
#define __ALIGNER_H__

#include <cstdint>

class Aligner{
public:
	static void alignBlocks(std::size_t* size_bytes);
	
private:
	const uint8_t mAlignment = sizeof(intptr_t);
};

#endif //__ALIGNER_H__