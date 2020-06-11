#include <iostream>
#include <vector>

template <typename T, std::size_t N>
std::size_t count_array_length(const T (&pPoint)[N])
{
	std::cout << "The length of the array is " << N << std::endl;
	return N;
}

int main()
{
	int a[10];
	char b[20];
	std::vector<int> c[30];

	count_array_length(a);
	count_array_length(b);
	count_array_length(c);

	return 1;
}
