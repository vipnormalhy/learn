#include <iostream>

/* first main 
int main()
{
	// operator returns left value
	// can use namespace
	std::cout << "Enter two Numbers " << std::endl;

	int var1, var2;

	std::cin >> var1 >> var2;

	std::cout << "The sum of " << var1 << "and " << var2 << "is " << var1 + var2 << std::endl;

	return 1;
}
*/

/*
int main()
{
	std::cout << "Hello World!" << std::endl;
	return 1;
}*/

//int main()
//{
//	std::cout << "/*";
//	std::cout << "/*";
//}*/

int main()
{
	int sum = 0;

	for (int i = 50; i <= 100; i++){
		sum += i;
	}

	std::cout << "For result is " << sum << std::endl;

	int i = 50;
	sum = 0;
	while (i <= 100)
	{
		sum += i++;
	}

	std::cout << "While result is " << sum << std::endl;

	return 1;
}


