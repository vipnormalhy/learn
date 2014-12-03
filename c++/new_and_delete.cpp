#include <iostream>

int main()
{
	int *p = new int(1024);
	
	std::cout << p << std::endl;
	std::cout << *p << std::endl;

	delete p;
	return 1;
}
