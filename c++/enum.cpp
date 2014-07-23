#include <iostream>

int main()
{
	typedef enum {Chinese, German, Spainish} flag_type;
	flag_type a = Chinese;

	std::cout << a << std::endl;

	return 1;
}
