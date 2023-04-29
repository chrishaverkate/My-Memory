#include <my-memory/allocator_factory.h>

#include "my_malloc.h"
#include "fixed_malloc.h"


using std::make_unique;
using std::unique_ptr;

std::unique_ptr<MyMemory> AllocatorFactory::create(AllocatorType type) {
	switch (type) {
	case AllocatorType::MY_MALLOC:
		return make_unique<MyMalloc>();
	case AllocatorType::FIXED_SIZE_ALLOCATOR:
		return make_unique<FixedMalloc>();
	default:
		return nullptr;
	}
}
