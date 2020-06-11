#include <iostream>

class test{
public:
	test(const int value);
	test();
	test &operator=(int value);
//private:
	test(const test &temp_obj); // copy constructor
private:
	int a;
};

test::test()
{
	a = 0;
}

test::test(const int value)
{
	std::cout << "Enter Constructor" << std::endl;
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

class testb{
public:
	testb(const testb &obj);
	testb(const int value);
	testb(const test &obj);
private:
	test cTestobj;
	int c;
};

testb::testb(const testb &obj)
{
	c = obj.c;
	cTestobj = obj.cTestobj;

	std::cout << "Enter b copy constructor" << std::endl;
}

testb::testb(const int value)
{
	c = value;

	std::cout << "Enter b constructor" << std::endl;
}

testb::testb(const test &obj)
{
	c = 0;
	cTestobj = obj;

	std::cout << "Enter b class constructor" << std::endl;
}

int main()
{
	std::cout << "Enter main" << std::endl;

	std::cout << "Init object by direct method" << std::endl;
	test b(3);

	std::cout << "Init object by operate = " << std::endl;
	test c = 3;

	// std::cout << "Iinit object by other object" << std::endl;
	// test d = c;

	// test e(c);

	// std::cout << "change value" << std::endl;
	// e = 4;

	// test f;

	// f = 5;

	// testb g(f);
	// testb h = test();

	return 1;
}
