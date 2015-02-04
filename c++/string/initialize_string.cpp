#include <string>
#include <iostream>

using namespace::std;

int main()
{
	string a(10, 'c');
	string *pStr;

	cout << a << endl;

	cout << a.size() << endl;

	pStr = &a;
	cout << pStr << endl;

	a += "ddddd";

	pStr = &a;
	cout << pStr << endl;

	return 1;
}
