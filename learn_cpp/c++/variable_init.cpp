#include <iostream>

double calc(float a, float b)
{
	return (double)a+b;
}

int main()
{
	int lang;
	double calc_value = calc(4.0, 5.0);
	std::cin >> lang;

	std::cout << lang << calc_value << std::endl;

	return 1;
}
