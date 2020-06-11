#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include "container.h"

using namespace std;

int test_vector()
{
	std::vector<int> vi{0,1,2,3,4};
	int i = 0;

	cout << "The size of vi is " << vi.size() << endl;
	vi = {5,6,};
	cout << "The size of vi is " << vi.size() << endl;

	cout << "The content of vi is ";
	for (vector<int>::iterator iter = vi.begin(); iter != vi.end(); iter++, i++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 1;	
}

int putout_elem(const string &s)
{
	cout << s << endl;
	return 1;
}

int putout_elem2(const pair<string ,int> &p)
{
	cout << "key = " << p.first << " value = " << p.second << endl;

	return 1;
}

int test_set()
{
	vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};

	set<string> ss(vs.begin(), vs.end());

	for_each(ss.begin(), ss.end(), putout_elem);

	cout << "This is the END of test_set" << endl;
	return 1;
}

int test_multiset()
{
	vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};
	
	multiset<string> ss(vs.begin(), vs.end());

	for_each(ss.begin(), ss.end(), putout_elem);

	cout << "This is the END of test_multiset" << endl;
	
	return 1;
}

int test_map()
{
	vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};

	map<string , int> ms;

	for (auto iter = vs.begin(); iter != vs.end(); iter++)
	{
		auto find_iter = ms.find(*iter);
		if (find_iter == ms.end())
		{
			// 4种插入方式
			ms.insert({*iter, 1});
			ms.insert(make_pair(*iter, 1));
			ms.insert(pair<string, int>(*iter, 1));
			ms.insert(map<string, int>::value_type(*iter, 1));
		}
		else
		{
			++find_iter->second;
		}
	}

	cout << ms.size() << endl;
	for_each(ms.begin(), ms.end(), putout_elem2);

	cout << "This is the END of test_map" << endl;
	
	return 1;
}

int test_multimap()
{
	vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};

	multimap<string , int> ms;

	for (auto iter = vs.begin(); iter != vs.end(); iter++)
	{
		auto find_iter = ms.find(*iter);
		if (find_iter == ms.end())
		{
			// 4种插入方式
			ms.insert({*iter, 1});
			ms.insert(make_pair(*iter, 1));
			ms.insert(pair<string, int>(*iter, 1));
			ms.insert(map<string, int>::value_type(*iter, 1));
		}
		else
		{
			++find_iter->second;
		}
	}

	cout << ms.size() << endl;
	for_each(ms.begin(), ms.end(), putout_elem2);

	cout << "This is the END of test_multimap" << endl;
	
	return 1;	
}

int statistic_word_count()
{
	vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};

	map<string, int> ms;

	// first method to use insert
	for (auto iter = vs.begin(); iter != vs.end(); iter++)
	{
		pair<map<string, int>::iterator, bool> ret = ms.insert({*iter, 1});

		if (!ret.second)
		{
			ret.first->second++;
		}
	}
	for_each(ms.begin(), ms.end(), putout_elem2);

	// second method to use []
	//ms = {};
	//ms.erase(ms.begin(), ms.end());
	for (auto iter = ms.begin(); iter != ms.end(); iter++)
	{
		cout << "erase " << iter->first << " num " << ms.erase(iter->first) << endl;
	}
	cout << "map reset, size is " << ms.size() << endl;
	for (auto iter = vs.begin(); iter != vs.end(); iter++)
	{
		ms[*iter] += 1;
	}
	for_each(ms.begin(), ms.end(), putout_elem2);

	cout << "This is the END of statistic word count" << endl;

	return 1;
}

int test_unordered_map()
{
	vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtls"};

	unordered_map<string, int> ums;

	for (auto iter = vs.begin(); iter != vs.end(); iter++)
	{
		cout << "The bucket count of map is " << ums.bucket_count() << endl;
		cout << "The Max bucket count of map is " << ums.max_bucket_count() << endl;
		ums[*iter] += 1;

		cout << "The bucket index of \"" << *iter << "\" is " << ums.bucket(*iter) << endl;
	}

	for (unsigned int i = 0; i < ums.bucket_count(); i++)
	{
		for (auto iter = ums.begin(i); iter != ums.end(i); iter++)
		{
			cout << "The Buckt(" << i << ")" << " elem is(key=" << iter->first << ") value = (" << iter->second << ")" << endl;
		}
	}

	for_each(ums.begin(), ums.end(), putout_elem2);

	cout << "The bucket count of map is " << ums.bucket_count() << endl;

	cout << "This is the END of test_unordered_map" << endl;
	return 1;
}
	

int main()
{
	test_vector();

	test_set();
	test_multiset();

	test_map();
	test_multimap();

	statistic_word_count();

	test_unordered_map();
}
