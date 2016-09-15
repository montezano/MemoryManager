#include "Aligner.h"

void Aligner::alignBlocks(std::size_t* size_bytes){
	if(*size_bytes % sizeof(intptr_t) != 0) {
		*size_bytes = (*size_bytes
		 - (*size_bytes % sizeof(intptr_t)))
		 + sizeof(intptr_t);
	}
}
