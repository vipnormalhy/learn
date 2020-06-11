#include <iostream>
#include <string>

std::string get_string_from_stdio()
{
	std::string oneline;

	std::getline(std::cin, oneline);

	return oneline;
}

int main()
{
	std::string line;
	int confirm_char;

	// explanation
	std::cout << "I will link all your input, y/Y for end input" << std::endl;
	
	while (confirm_char != 'y' && confirm_char != 'Y')
	{
		// get a line from stdio
		line += get_string_from_stdio();

		// if end?
		std::cout << "Input End?y/Y for end(ENTER for confirm)" << std::endl;
		
		// get the first char for confirm
		confirm_char = std::cin.get();
		// drop the left
		while(std::cin.get() != '\n')
		{
		}
	}

	// put words to stdout and replace the punctuation
	for (std::string::size_type index = 0; index < line.size(); index++)
	{
		if (std::ispunct(line[index]))
		{
			line[index] = ' ';
		}
	}
	std::cout << "All Input is :" << line << std::endl;
	return 1;
}
