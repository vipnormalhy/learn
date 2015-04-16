#include <iostream>

class test {
public:
	static int a;
	const static float b = 3.0;
	test();
	static int count_num();
private:
	int c;
};

int test::count_num()
{
	return test::a;
}

test::test()
{
	c = 1;
}

int test::a = 3;

int main()
{
	test oB;

	std::cout << test::a << std::endl;

	std::cout << "Use static func " << test::count_num() << std::endl;

	return 1;
}
     
