#include <iostream>
#include "move.h"

// copy construct function
Movetest::Movetest(Movetest &movetest)
{
	std::cout << "Enter Movetest copy construct " << std::endl;
	pv = movetest.pv;
}

Movetest::Movetest(Movetest &&movetest) noexcept
{
	std::cout << "Enter Movetest move copy construct " << std::endl;
	pv.swap(movetest.pv);
}

Movetest &Movetest::operator=(const Movetest &movetest) &
{
	this->pv = movetest.pv;

	std::cout << "Enter Movetest copy = operator" << std::endl;

	return *this;
}

Movetest &Movetest::operator=(Movetest &&movetest) & noexcept
{
	this->pv.swap(movetest.pv);

	std::cout << "Enter Movetest move = operator" << std::endl;

	return *this;
}

int Movetest::malloc(const std::initializer_list<int> vi)
{
	pv = std::make_shared<std::vector<int>> (vi);

	if (!pv)
	{
		return 0;
	}

	return 1;
}

int main()
{
	Movetest *test(new Movetest);

	test->malloc({34, 32});

	Movetest test1(std::move(*test));
	delete test;

	Movetest test3;
	test3.malloc({45, 1});
	Movetest test4;

	test4 = test3;
	return 1;
}
