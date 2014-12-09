#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

// Try to create a file to store passwd for user
// Use istream ostream ifstream ofstream stringstream
// no class,only functions

// To find if the user file exists.
int user_exist(const std::string &filename)
{
	const char *c_filepath = filename.c_str();

	if (access(c_filepath, 0) != 0)
	{
		return 0;
	}

	return 1;
}

// check if the passwd  is correct
int fit_passwd_in_file(std::string &username, std::string &passwd)
{
	return 0;
}

// 1. Input a user name
// 2. Find if the user name exists.
// 3. Check the passwd or Input a new passwd
// 4. Wait to input another user name
int main(int argc, char *argv[])
{
	std::string username;

	std::cout << "Enter a UserName: " << std::endl;

	// cin ties with cout, so we need not to do anything
	while (std::cin >> username)
	{
		if (user_exist(username))
		{
			std::cout << "Exist User.Please input your password(Not Display): " << std::flush;
			//std::cout << "Exist User.Please input your password(Not Display): " << std::ends;
			// do not display what's input
			std::cin.tie(0);

			std::string passwd;
			std::cin >> passwd;

			// display what's input
			std::cin.tie(&std::cout);

			// check the passwd
			if (fit_passwd_in_file(username, passwd))
			{
				std::cout << "Your put the correct passwd" << std::endl;
				std::cout << std::ends;

				// goto the first step
				std::cout << "Enter a UserName: " << std::endl;
				continue;
			}
			else
			{
				std::cout << "Your put the correct passwd" << std::endl;
				std::cout << std::ends;

				// goto the first step
				std::cout << "Enter a UserName: " << std::endl;
				continue;
			}
		}
		else
		{
			std::string tmp_passwd, confirm_passwd;

			std::cout << "Please Enter a New Password for " << username << std::flush;

			std::cin.tie(0);
			std::cin >> tmp_passwd;
			std::cin.tie(&std::cout);

			std::cout << "Please Enter the passwd for checking" << std::flush;
			std::cin.tie(0);
			std::cin >> confirm_passwd;
			std::cin.tie(&std::cout);

			if (tmp_passwd != confirm_passwd)
			{
				std::cout << "Passwd is wrong" << std::endl;
				// goto the first step
				std::cout << "Enter a UserName: " << std::endl;
				continue;
			}
			else
			{
				std::fstream passwdstream;
				std::string save_file_path;
				std::stringstream strm;

				strm.str(save_file_path);

				strm << "passwd_file";
				
				passwdstream.open(strm.str(), std::fstream::in | std::fstream::out);
				if (!passwdstream)
				{
					std::cout << "Cannot open file, error " << passwdstream.rdstate() << std::endl;
					std::cout << "Enter a UserName: " << std::endl;
					continue;
				}
				passwdstream << tmp_passwd << std::flush;
				passwdstream.close();
				// goto the first step
				std::cout << "Enter a UserName: " << std::endl;
				continue;
			}
		}
	}

	return 1;
}
