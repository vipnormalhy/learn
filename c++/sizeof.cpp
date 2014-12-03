#include <iostream>

int main()
{
	int a;
	int *p;

	int *&y = p;

	std::cout << sizeof a << std::endl;

	p = (int *)malloc(sizeof(int));

	*p = 3;

	std::cout << *y << std::endl;
	std::cout << sizeof y << std::endl;

	return 1;
}
