#include <iostream>
#include <fstream>
#include "class.h"

const unsigned int TestObject::get_ref_amount()
{
	return ref;
}

void TestObject::tie_test()
{
	// int i;
	// std::ostream *pOld;
	
	// pOld = std::cin.tie(nullptr);
	
	// std::cout << "Enter a number:" << std::endl;
	// while(std::cin >> i)
	// {
	// 	std::cout << i;
	// }

	// std::cout << "Enter a number(tie cout): " << std::endl;
	// std::cin.tie(pOld);
	// while(std::cin >> i)
	// {
	// 	std::cout << i;
	// }

	// return;

	std::ofstream fstrm;
	std::ostream *pOld = nullptr;
	int c;

	fstrm.open("testobj.txt");

	// fstrm will not flush without tie
	pOld = std::cin.tie(&fstrm);
	while(std::cin >> c)
	{
		fstrm << c;
	}
	
	fstrm.close();

	std::cin.tie(pOld);
}

// TestObject::TestObject(int d_t, int ref_t = 0, std::string path_t = "")
// {
// 	ref = ref_t;
// 	object_path = path_t;

// 	std::cout << "Enter constructor function" << std::endl;
// }

int TestObject::get_d() const
{
	int *p = const_cast<int *>(&d);

	*p += 1;
	return *p;
}

int main()
{
	TestObject to;
	TestObject to2;
	int test_converting = 3;

	std::cout << to.get_ref_amount() << std::endl;
	std::cout << to.get_path() << std::endl;

	to = static_cast<TestObject>(test_converting);
	to2 = static_cast<TestObject>(test_converting);

	std::cout << to.get_ref_amount() << std::endl;
	std::cout << to2.get_ref_amount() << std::endl;

	to.tie_test();

	std::cout << to.get_d() << std::endl;
	
	return 1;
}
