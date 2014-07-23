#include <iostream>

double calc(float a, float b)
{
	return (double)a+b;
}

int main()
{
	int lang;
	double calc = calc(4.0, 5.0);
	std::cin >> lang;

	std::cout << lang << std::endl;

	return 1;
}
