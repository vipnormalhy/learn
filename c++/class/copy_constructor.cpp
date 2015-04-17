#include <iostream>

class test{
public:
	test(test &); // copy constructor
	test(int value);
	test &operator=(int value);
private:
	int a;
};

test::test(test &obj)
{
	std::cout << "Enter copy test" << std::endl;
}

test::test(int value)
{
	std::cout << "Enter constructor" << std::endl;
	a = value;
}

test & test::operator=(int val)
{
	a = val;

	std::cout << "Enter Operator func" << std::endl;
	return *this;
}

int main()
{
	std::cout << "Enter main" << std::endl;

	std::cout << "Init object by direct method" << std::endl;
	test b(3);

	std::cout << "Init object by operate = " << std::endl;
	test c = 3;

	std::cout << "Iinit object by other object" << std::endl;
	test d = c;

	return 1;
}
