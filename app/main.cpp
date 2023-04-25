#include <iostream>
#include <my-memory/message.h>

int main (int argc, char** argv) {
	Message msg;
	printf("%s\n", msg.get_hello()->c_str());
	return 0;
}
