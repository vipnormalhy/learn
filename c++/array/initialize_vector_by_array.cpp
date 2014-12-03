#include <string>
#include <iostream>
#include <vector>

int main()
{
	char *p[] = {"abc", "bcd", "cde", "def"};
	char *p1;

	std::vector<std::string> v_s(p, p+ (sizeof(p))/sizeof(char *));

	std::cout << *p << "," << v_s[0] << std::endl;

	std::cout << "sizeof array is " << sizeof(p) << std::endl;
	std::cout << "sizeof point is " << sizeof(p1) << std::endl;

	return 1;
}
