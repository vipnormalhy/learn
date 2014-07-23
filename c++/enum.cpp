#include <iostream>

int main()
{
	enum flag_type {Chinese, German, Spainish};

	flat_type a(German);

	std::cout << a << std::endl;

	return 1;
}
