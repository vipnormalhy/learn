#include <iostream>

int main()
{	
	int a;
	double b;
	int c;
	int *p;

	a = 3;
	b = 3.14;

	c = a + static_cast<int>(b);
	p = reinterpret_cast<int *>(&b);

	std::cout << c << std::endl;
	std::cout << *p << std::endl;

	return 1;
}
