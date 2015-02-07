#include <stack>
#include <queue>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	// find the word between '(' and ')'
	std::string strInput;

	while(std::cin >> strInput)
	{
		if (strInput.empty())
		{
			continue;
		}

		std::string::size_type size;
		std::stack <char> cStack;
		
		size = strInput.size();
		for (int i = 0; i < size; i++)
		{
			if (strInput[i] == ')')
			{
				if (cStack.empty())
				{
					std::cout << "Cannot find the fit '('" << std::endl;
					continue;
				}
				else
				{
					int fit_ok = 0;
					
					// put out the hole find string unitl last '('
					std::cout << strInput[i] << std::flush;
					while(!cStack.empty())
					{
						char c = cStack.top();
						cStack.pop();
						std::cout << c << std::flush;

						if (c == '(')
						{
							fit_ok = 1;
							break;
						}
					}
				}
			}
			else
			{
				cStack.push(strInput[i]);
			}
		}
			
	}

	return 1;
}
