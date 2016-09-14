#include <cstdint>

class Aligner{
public:
	static void allignBlocks(std::size_t* size_bytes);
	
private:
	const uint8_t mAlignment = sizeof(intptr_t);
};