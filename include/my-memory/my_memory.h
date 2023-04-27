#pragma once
#include <cstddef>
#include <stdint.h>

class MyMemory {
public:
	/** @brief Because c++ */
	virtual ~MyMemory() = default;

	/** @brief behaves like malloc.
	 * 		Allocates memory from the internally managed pool or null if no memory is available.
	 * @param size number of bytes to allocate
	 * @return pointer to starting address or null
	 */
	virtual void* malloc(size_t size) = 0;

	/** @brief behaves like free.
	 * 		Removes the reservation of the memory, making it available for future allocations.
	 * @param ptr starting address of the memory to free
	 */
	virtual void free(void*& ptr) = 0;

	/** @brief The number of times malloc has been called and returned a valid pointer,
	 * 		without a corresponding free.
	 * @return number of allocations currently reserved
	 */
	virtual uint64_t current_allocations() = 0;

	/** @return The number of bytes currently free in the pool. */
	virtual uint64_t available_memory() = 0;

	/** @brief The user will request a number of bytes needed.
	 * 		This helps track the requested amount
	 * @return The number of bytes that have been requested for use
	 */
	virtual uint64_t used_memory_requested() = 0;

	/** @brief The bytes needed to fulfill the request may be larger than the requested amount.
	 * 		This helps track the overhead needed to fulfill the request.
	 * @return The number of bytes currently allocated.
	 */
	virtual uint64_t used_memory_actual() = 0;
};
