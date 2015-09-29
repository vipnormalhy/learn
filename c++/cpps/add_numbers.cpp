// Add the number the user input
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdarg>
#include <cstdlib>

auto varargs_func(int, ...) -> int;

int learn_about_type_convert()
{
	int v1 = 0, v2 = 0;
	unsigned int u1 = 10;
	int i1 = -42;

	std::cout << "Test size of some types :";
	std::cout << "long long = " << sizeof(long long) << ";int = " << sizeof(int) << ";long = " << sizeof(long) << std::endl;

	std::cout << "unsigned(10) + int(-42) (use static cast)" << u1 + static_cast<unsigned int>(i1) << std::endl;
	std::cout << "int(-42) + unsigned(10) (use static cast)" << i1+ static_cast<int>(u1) << std::endl;

	std::cout << "unsigned(10) + int(-42) (compiler's default cast)" << u1 + i1 << std::endl;
	std::cout << "int(-42) + unsigned(10) (compiler's default cast)" << i1+ u1 << std::endl;

	std::cout << "Please Enter two nubers : " << std::endl;
	std::cin >> v1 >> v2;

	std::cout << "The number " << v1 << " and " << v2 << " is : " << v1 + v2 << std::endl;

	return EXIT_SUCCESS;
}

// compiler display warning about narrowing conversion but not error
int learn_about_list_initization()
{
	float a = 4.5f;
	int b{a};
	int c = {a};
	int d = a;
	int e(a);

	std::cout << a << b << c << d << e << std::endl;

	return EXIT_SUCCESS;
}

int const_expression()
{
	const int a = 4;
	constexpr int b = a * 4;
	int c = 5;
	const int d = c * 4;

	std::cout << a << b << std::endl;
	std::cout << c << d << std::endl;

	return EXIT_SUCCESS;
}

int test()
{
	int a = 3;
	auto b = a;
	decltype(a) c;
	std::vector<int> va;
	
	std::cout << "sizeof va = " << sizeof va << std::endl;
	for (int i = 0; i < 1000; i++)
	{
		va.push_back(i);
	}
	std::cout << "sizeof va = " << sizeof va << std::endl;

	int d = (3+4,4);
	std::cout << "d = " << d << std::endl;

	c = a;

	std::cout << a << b << c << std::endl;
	return EXIT_SUCCESS;
}

int print_size(int *p_array)
{
	std::cout << "param size is = " << sizeof p_array << std::endl;
	return EXIT_SUCCESS;
}

int calc_array_size()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pInt;

	std::cout << "initial size = " << sizeof a << std::endl;
	std::cout << "size of array = " << sizeof(a)/sizeof(int) << std::endl;

	pInt = &a[0];
	std::cout << "size of first eleme pointer = " << sizeof pInt << std::endl;

	print_size(a);
	return EXIT_SUCCESS;
}

int varargs_func(const char *msg, ...)
{
	va_list v_list;
	int param;

	va_start(v_list, msg);
	while((param = va_arg(v_list, int)) != -1)
	{
		std::cout << param << std::endl;
	}
	va_end(v_list);
	return EXIT_SUCCESS;
}

int main()
{
	//learn_about_type_convert();
	//learn_about_list_initization();
	//const_expression();
	//test();
	//calc_array_size();
	varargs_func("errr", 10, 100, 1000, 1, -1);
	varargs_func("dddd", 1, 1, -1);

	return EXIT_FAILURE;
}

