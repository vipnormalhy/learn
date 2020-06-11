#include <iostream>
#include <cstring>

template <typename N>
int compare(N v1, N v2)
{
	if (v1 < v2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

template <unsigned int N, unsigned int M>
int string_compare(const char (&p1)[N], const char (&p2)[M])
{
	std::cout << N << " " << M << std::endl;

	return strcmp(p1, p2);
}

int main()
{
	std::cout << compare(1, 2) << std::endl;
	std::cout << compare("ab", "dd") << std::endl;

	std::cout << string_compare("mi", "di") << std::endl;

	return 1;
}
