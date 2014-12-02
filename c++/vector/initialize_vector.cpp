#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v_a(30);

	std::cout << v_a[0] << std::endl;

	std::vector< std::vector<int> > v_b;

	std::vector<std::string> v_c(10, "aaa");

	std::cout << v_c[2] << std::endl;

	std::vector<int>::size_type v_size = v_c.size();

	std::cout << v_size << std::endl;

	std::string test_push_str = "bcd";

	v_c.push_back(test_push_str);

	std::cout << v_c[10] << std::endl;

	return 1;
}
