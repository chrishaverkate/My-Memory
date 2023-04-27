#include <my-memory/allocator_factory.h>

#include "my_malloc.h"


using std::make_unique;
using std::unique_ptr;

std::unique_ptr<MyMemory> AllocatorFactory::create(AllocatorType type) {
	switch (type) {
	case AllocatorType::MY_MALLOC:
		return make_unique<MyMalloc>();
	case AllocatorType::FIXED_SIZE_ALLOCATOR:
		// TODO: Implement this
		return nullptr;
	default:
		return nullptr;
	}
}
