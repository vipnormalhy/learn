#include <iostream>

int reset(int *p)
{
	*p = 0;
	p = 0;

	std::cout << p << std::endl;
	return 1;
}

int main()
{
	int a = 10;
	int *p;

	p = &a;

	reset(p);

	std::cout << a << " " << p  << " " << *p << std::endl;
	return 1;
}
