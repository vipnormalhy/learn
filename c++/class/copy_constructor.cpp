#include <iostream>

class test{
public:
	test(const test &temp_obj); // copy constructor
	test(const int value);
	test();
	test &operator=(int value);
private:
	int a;
};

test::test()
{
	a = 0;
}

test::test(const int value)
{
	a = value;
}

test::test(const test &obj)
{
	std::cout << "Enter copy test" << std::endl;

	a = obj.a;
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

	test e(c);

	std::cout << "change value" << std::endl;
	e = 4;

	test f;

	f = 5;

	return 1;
}
