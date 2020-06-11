#include <vector>
#include <iostream>

int main()
{
	int i = 0;

	std::vector<int> v_i(10);
	std::vector<int>::iterator iter;

	for (iter = v_i.begin();iter != v_i.end(); iter++)
	{
		*iter = i++;
	}

	for (std::vector<int>::const_iterator citer = v_i.begin(); citer != v_i.end(); citer++)
	{
		std::cout << *citer << std::endl;
	}

	std::cout << *(v_i.begin() + v_i.size()/2) << std::endl;

	return 1;
}
