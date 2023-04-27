#include <cstring>
#include <iostream>
#include <my-memory/allocator_factory.h>
#include <my-memory/my_memory.h>

using std::string;
using std::unique_ptr;

int main (int argc, char** argv) {
	unique_ptr<MyMemory> allocator = AllocatorFactory::create(AllocatorType::MY_MALLOC);
	string message = "Hello World!";
	char* custom_bucket = 0;

	printf("Custom Bucket:\n");
	printf("address (pre-alloc): %p\n", custom_bucket);

	custom_bucket = (char*)allocator->malloc(message.length() + 1);
	printf("address (alloc'd)  : %p\n", custom_bucket);
	custom_bucket[message.length()] = '\0';

	printf("Message (pre-copy) : ");
	for (int i(0); i < message.length(); ++i) {
		printf("%x", (unsigned int)(custom_bucket[i]));
	}
	printf("\n");

	strcpy(custom_bucket, message.c_str());
	printf("Message (copied)   : %s\n", custom_bucket);

	allocator->free(reinterpret_cast<void*&>(custom_bucket));

	return 0;
}
