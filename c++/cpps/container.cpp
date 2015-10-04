#include <vector>
#include <iostream>
#include "container.h"

using namespace std;

int main()
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
