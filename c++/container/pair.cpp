#include <utility>
#include <iostream>

int main(int argc, char *argv[])
{
	std::pair<int, int> pairTest;
	int first, second;

	std::cin >> first >> second;
	pairTest.first = first;
	pairTest.second = second;

	std::cout << pairTest.first << " " << pairTest.second << std::endl;

	return 1;
}
