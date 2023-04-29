#include <gtest/gtest.h>

#include <fixed_malloc.h>
#include <cstring>

TEST(FixedMallocTests, create) {
	FixedMalloc my_malloc;
}

TEST(FixedMallocTests, malloc) {
	FixedMalloc my_malloc;
	void* ptr = my_malloc.malloc(10);
	ASSERT_NE(ptr, nullptr);
	my_malloc.free(ptr);
}

TEST(FixedMallocTests, multiple_malloc) {
	FixedMalloc my_malloc;

	char* ptr1 = (char*)my_malloc.malloc(8);
	strcpy(ptr1, "Hi");
	ASSERT_STREQ(ptr1, "Hi");

	char* ptr2 = (char*)my_malloc.malloc(8);
	strcpy(ptr2, "Hola");
	ASSERT_STREQ(ptr2, "Hola");

	ASSERT_NE(ptr1, ptr2);
}

TEST(FixedMallocTests, free) {
	FixedMalloc my_malloc;
	void* ptr = my_malloc.malloc(10);
	my_malloc.free(ptr);
	ASSERT_EQ(ptr, nullptr);
}

//TEST(FixedMallocTests, current_allocations_first_allocation) {
//	FixedMalloc my_malloc;
//	void* ptr = my_malloc.malloc(10);
//	ASSERT_EQ(my_malloc.current_allocations(), 1);
//	my_malloc.free(ptr);
//	ASSERT_EQ(my_malloc.current_allocations(), 0);
//}
//
//TEST(FixedMallocTests, current_bytes_requested_first_allocation) {
//	FixedMalloc my_malloc;
//	void* ptr = my_malloc.malloc(10);
//	ASSERT_EQ(my_malloc.used_memory_requested(), 10);
//	my_malloc.free(ptr);
//	ASSERT_EQ(my_malloc.used_memory_requested(), 0);
//}
//
