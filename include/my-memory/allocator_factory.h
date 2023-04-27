#pragma once

#include <my-memory/my_memory.h>
#include <memory>

enum class AllocatorType {
	MY_MALLOC,
	FIXED_SIZE_ALLOCATOR,
};

class AllocatorFactory {
public:
	static std::unique_ptr<MyMemory> create(AllocatorType type);
};
