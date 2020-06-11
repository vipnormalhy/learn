#include <iostream>
#include <string>

std::string get_oneline_by_cin()
{
	std::string line;

	std::cin >> line;

	return line;
}

std::string get_oneline_by_getline()
{
	std::string line;

	std::getline(std::cin, line);

	return line;
}

int main(int argc, char **argv)
{
	std::string oneline;

	// get one line from std input
	std::cout << "Input one line" << std::endl;

	oneline = get_oneline_by_cin();

	std::cout << "Your Input line is :" << oneline << std::endl;

	// get the last char
	std::cin.get();

	// get one line from std input while using getoneline function
	std::cout << "Input another line" << std::endl;
	oneline = get_oneline_by_getline();
	std::cout << "Your input line is :" << oneline << std::endl;

	return 1;
}
