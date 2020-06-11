#include <iostream>
#include <fstream>
#include <sstream>
#include "pointer.h"

int FileInfo::read_fileinfo()
{
	std::string line;
	
	if (filename.size() == 0)
	{
		std::cout << "No file name.Please use set_filename to set file path first" << std::endl;
		return -1;
	}

	std::fstream fileobj(filename, std::fstream::in);

	// clear mpword info
	mpword.clear();

	// read open file
	// while (fileobj >> line)
	// {
	// }

	int linenum = 0;
	
	while (getline(fileobj, line))
	{
		std::stringstream ss(line);
		std::string word;

		while (ss >> word)
		{
			// word exists
			if (mpword.find(word) != mpword.end())
			{
				std::shared_ptr<std::set<int>> pold_linenum = mpword[word];
				pold_linenum->insert(linenum);
			}
			else
			{
				//std::shared_ptr<std::set<int>> pnew_linenum(new std::set<int>);
				std::shared_ptr<std::set<int>> pnew_linenum = std::make_shared<std::set<int>> ();
				pnew_linenum->insert(linenum);
				mpword[word] = pnew_linenum;
			}
		}
		linenum += 1;
	}

	std::cout << "File " << filename << " has " << linenum << " lines" << std::endl;

	fileobj.close();

	return 1;
}

std::shared_ptr<std::set<int>> *FileInfo::get_word_lines(const std::string word)
{
	std::unordered_map<std::string, std::shared_ptr<std::set<int>>>::iterator iter;
		
	if (mpword.empty())
	{
		return nullptr;
	}

	iter = mpword.find(word);
	if (iter == mpword.end())
	{
		return nullptr;
	}
	else
	{
		return &iter->second;
	}

	return nullptr;
}

inline void FileInfo::set_filename(const std::string open_filepath)
{
	if (mpword.empty())
	{
		filename = open_filepath;
	}
	else
	{
		// release all data
		mpword = {};
		filename = open_filepath;
	}
}

void putout_data(const std::shared_ptr<std::set<int>> *pline)
{
	if (!pline)
	{
		std::cout << " Cannot find word!" << std::endl;
		
		return;
	}
	
	auto iter = (*pline)->begin();

	while (iter != (*pline)->end())
	{
		std::cout << *iter++ << " ";
	}
	std::cout << std::endl;
}
	
int main()
{
	FileInfo fi;

	fi.set_filename("container.cpp");
	fi.read_fileinfo();

	// find include
	std::cout << "The word \"if\" appears in " << std::flush;
	putout_data(fi.get_word_lines("if"));

	fi.set_filename("algorithm.cpp");
	fi.read_fileinfo();
	std::cout << "The word \"if\" appears in " << std::flush;
	putout_data(fi.get_word_lines("if"));
		
	std::cout << "The word \"include\" appears in " << std::flush;
	putout_data(fi.get_word_lines("include"));	
	
	return 1;
}
