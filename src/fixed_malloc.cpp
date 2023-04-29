#include "fixed_malloc.h"

void* FixedMalloc::malloc(size_t size) {
	// 10 bytes requested
	// 2 blocks (8 bytes each)
	return (void*)&_memory[0];
}

void FixedMalloc::free(void*& ptr) {
	ptr = nullptr;
}

uint64_t FixedMalloc::current_allocations() {
	return 0;
}

uint64_t FixedMalloc::available_memory() {
	return 0;
}

uint64_t FixedMalloc::used_memory_requested() {
	return 0;
}

uint64_t FixedMalloc::used_memory_actual() {
	return 0;
}
