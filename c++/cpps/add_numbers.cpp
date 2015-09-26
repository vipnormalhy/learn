// Add the number the user input
#include <iostream>
#include <string>
#include <string.h>

int main()
{
	int v1 = 0, v2 = 0;
	unsigned int u1 = 10;
	int i1 = -42;

	std::cout << "Test size of some types :";
	std::cout << "long long = " << sizeof(long long) << ";int = " << sizeof(int) << ";long = " << sizeof(long) << std::endl;

	std::cout << "unsigned(10) + int(-42) (use static cast)" << u1 + static_cast<unsigned int>(i1) << std::endl;
	std::cout << "int(-42) + unsigned(10) (use static cast)" << i1+ static_cast<int>(u1) << std::endl;

	std::cout << "unsigned(10) + int(-42) (compiler's default cast)" << u1 + i1 << std::endl;
	std::cout << "int(-42) + unsigned(10) (compiler's default cast)" << i1+ u1 << std::endl;

	std::cout << "Please Enter two nubers : " << std::endl;
	std::cin >> v1 >> v2;

	std::cout << "The number " << v1 << " and " << v2 << " is : " << v1 + v2 << std::endl;

	return 1;
}

