#include <iostream>

int test_foo(const int &a, const int &b)
{
	return a;
}

int main()
{
	int a = 3, b = 4;

	a = test_foo(a, b);

	std::cout << a << b << std::endl;
	return 1;
}
