#include <iostream>
#include <string>

int main()
{
	std::string a, b;

	a = (std::string)("big");
	b = "pig" + a;

	std::cout << "a is " << a << ";b is " << b << std::endl;

	// put out size and empty

	std::cout << "size of a is:" << a.size() << " and sizeof b is :" << b.size() << std::endl;
	std::cout << "a is empty: " << a.empty() << std::endl;

	return 1;
}
