#pragma once
#include <my-memory/my_memory.h>

#include <stdint.h>
#include <map>

class MyMalloc : public MyMemory {
public:
	void* malloc(size_t size) override;
	void free(void*& ptr) override;
	uint64_t current_allocations() override;
	uint64_t available_memory() override;
	uint64_t used_memory_requested() override;
	uint64_t used_memory_actual() override;

private:
	uint64_t _requested_memory = 0;
	std::map<void*, size_t> _allocations_map;
};
