#include <iostream>
#include <string>

int main()
{
	std::string a("I am a handsome boy!\n");

	// the behivor is undefined
	for (std::string::size_type index = 0; index < 30; index++) 
	{
		std::cout << "The size of string is " << a.size() << " now index is " << index << " now char is " << a[index] << std::endl;
	}
	return 1;
}
