#include "my_malloc.h"

#include <cstdlib>

void* MyMalloc::malloc(size_t size) {
	void* ptr = std::malloc(size);
	_allocations_map[ptr] = size;
	_requested_memory += size;
	return ptr;
}

void MyMalloc::free(void*& ptr) {
	_requested_memory -= _allocations_map[ptr];
	_allocations_map.erase(ptr);
	std::free(ptr);
	ptr = nullptr;
}

uint64_t MyMalloc::current_allocations() {
	return _allocations_map.size();
}

uint64_t MyMalloc::available_memory() {
	return 0;
}

uint64_t MyMalloc::used_memory_requested() {
	return _requested_memory;
}

uint64_t MyMalloc::used_memory_actual() {
	return 0;
}
