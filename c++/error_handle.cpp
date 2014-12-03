#include <stdexcept>
#include <iostream>

#ifdef _DEBUG
int handle_runtime_error() {	
	std::cout << "Runtime error occured" << std::endl;
	return 1;
}
#endif

int main() {

#ifdef _DEBUG
	try {
		throw std::runtime_error("Test error");
	}
	catch(std::runtime_error) {
		handle_runtime_error();
		exit(-1);
	}
#endif

	return 1;
}
