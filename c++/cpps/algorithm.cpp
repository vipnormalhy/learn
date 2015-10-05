#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <functional>

int test_copy()
{
	std::vector<int> vi;
	int ai[] = {0,1,2,3,4,5};

	copy(std::begin(ai), std::end(ai), back_inserter(vi));

	for (std::vector<int>::iterator iter = vi.begin();iter != vi.end();iter++)
	{
		std::cout << *iter << std::endl;
	}
	
	return 1;
}

int test_replace()
{
	std::string s1;

	s1 = "I am a test string";
	std::string s2(s1.begin(), s1.end());
	std::cout << "s2 is " << s2 << std::endl;

	s2.clear();
	std::cout << "s2 is " << s2 << std::endl;

	replace_copy(s1.begin(), s1.end(), back_inserter(s2), 't', 'b');
	std::cout << "s2 is " << s2 << std::endl;
	std::cout << "s1 is " << s1 << std::endl;

	return 1;
}

int test_sort()
{
	std::vector<std::string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};
	std::vector<std::string>::iterator iter;

	sort(vs.begin(), vs.end());
	iter = unique(vs.begin(), vs.end());

	while(iter != vs.end())
	{
		iter = vs.erase(iter);
	}
	//vs.erase(iter, vs.end());

	for (iter = vs.begin(); iter != vs.end(); iter++)
	{
		std::cout << *iter << " " << std::flush;
	}
	std::cout << std::endl;

	vs = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};
	stable_sort(vs.begin(), vs.end());
	
	for (iter = vs.begin(); iter != vs.end(); iter++)
	{
		std::cout << *iter << " " << std::flush;
	}
	std::cout << std::endl;		    
	
	return 1;
}

static int global_i = 1;

int test_lambda1()
{
	int c = 1;
	std::vector<int> vi = {0,1,2,3,4,};
	
	auto func1 = [&c]() {c=45;return c;};
	auto func2 = [&vi]() -> std::vector<int> {vi[3] = 20;return vi;};
	auto func3 = [=]() {++global_i;};

	func2();
	std::cout << func2()[3] << vi[3] << std::endl;

	c = 10;
	std::cout << func1() << c << std::endl;

	std::cout << "global = " << global_i << std::endl;
	func3();
	std::cout << "global = " << global_i << " after lambda" << std::endl;
	
	return 1;
}

int putout_string(std::string &s, size_t len)
{
	if (s.size() > len)
	{
		std::cout << s << std::endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

int test_bind()
{
	std::vector<std::string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};

	using namespace std::placeholders;
	
	for_each(vs.begin(), vs.end(), bind(putout_string, _1, 3));
	find_if(vs.begin(), vs.end(), bind(putout_string, _1, 3));
	
	return 1;
}
	

int main()
{
	test_copy();
	test_replace();
	test_sort();
	test_lambda1();
	test_bind();

	return 1;
}
