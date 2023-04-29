#pragma once

#include "my-memory/my_memory.h"

class FixedMalloc : public MyMemory {
public:
	virtual ~FixedMalloc() = default;

	void* malloc(size_t size) override;
	void free(void*& ptr) override;
	uint64_t current_allocations() override;
	uint64_t available_memory() override;
	uint64_t used_memory_requested() override;
	uint64_t used_memory_actual() override;

private:
	void add_record(int block_offset, int block_span) {

	}

	void remove_record(int block_offset) {

	}

	static struct Record {
		unsigned char addr;
		unsigned char size;
	} _records[64];
	static char _memory[512];
};

inline FixedMalloc::Record FixedMalloc::_records[] = {0};
inline char FixedMalloc::_memory[] = {0};
