#include <gtest/gtest.h>

#include <my_malloc.h>

TEST(MyMallocTests, create) {
	MyMalloc my_malloc;
}

TEST(MyMallocTests, malloc) {
	MyMalloc my_malloc;
	void* ptr = my_malloc.malloc(10);
	ASSERT_NE(ptr, nullptr);
}

TEST(MyMallocTests, free) {
	MyMalloc my_malloc;
	void* ptr = my_malloc.malloc(10);
	my_malloc.free(ptr);
	ASSERT_EQ(ptr, nullptr);
}

TEST(MyMallocTests, current_allocations_first_allocation) {
	MyMalloc my_malloc;
	void* ptr = my_malloc.malloc(10);
	ASSERT_EQ(my_malloc.current_allocations(), 1);
	my_malloc.free(ptr);
	ASSERT_EQ(my_malloc.current_allocations(), 0);
}

TEST(MyMallocTests, current_bytes_requested_first_allocation) {
	MyMalloc my_malloc;
	void* ptr = my_malloc.malloc(10);
	ASSERT_EQ(my_malloc.used_memory_requested(), 10);
	my_malloc.free(ptr);
	ASSERT_EQ(my_malloc.used_memory_requested(), 0);
}
