#include <iostream>

template <typename T>
int compare(const T &a, const T &b)
{
	if (a < b)
	{
		return -1;
	}
	else if (a == b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	std::cout << compare(1, 0) << std::endl;

	std::cout << compare("abc", "cba") << std::endl;

	return 0;
}
