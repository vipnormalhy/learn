#include <string>
#include <iostream>
#include <unistd.h>

int main()
{
	std::string *p;

	std::cout << "I will new something" << std::endl;
	
	p = new std::string[10000];

	sleep(10);

	std::cout << "I will free them" << std::endl;

	delete [] p;

	sleep(10);

	return 1;

}
