#include <stack>
#include <string>
#include <iostream>

int main()
{
	// findout content between "(" and ")"
	// in sizeof.cpp file
	std::string filename("sizeof.cpp");
	std::ifstream infile;
	std::string line;

	infile.open(filename.c_str());
	if (!infile)
	{
		std::cout << "cannot open file " << filename << std::endl;
		return -1;
	}

	while (infile >> line)
	{
		std::cout << line;
	}

	return 0;
}
