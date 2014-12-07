#include <iostream>

double accumulate(int base) {
	int result = 1;

	std::cout << "come int function" << std::endl;
	for (int i = 0; i < 10; i++) {
		result *= base++;
	}

	return static_cast<double>(result);
}

double accumulate(float base) {
	double result = 1.0;

	std::cout << "com here handle by float" << std::endl;
	for (int i = 0; i < 10; i++) {
		result *= base;
		base += 1;
	}

	return result;
}

int main()
{
	int base = 3;

	std::cout << accumulate(base) << std::endl;

	float fbase = 3.8;

	std::cout << accumulate(fbase) << std::endl;

	return 1;
}
