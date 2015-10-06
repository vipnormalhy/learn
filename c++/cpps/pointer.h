#ifndef POINTER_H
#define POINTER_H

#include <map>
#include <string>
#include <memory>
#include <set>
#include <unordered_map>

class FileInfo
{
public:
	FileInfo() = default;
	int read_fileinfo();
	void set_filename(const std::string open_filepath);
	std::shared_ptr<std::set<int>> *get_word_lines(const std::string word);
private:
	std::unordered_map<std::string, std::shared_ptr<std::set<int>>> mpword;
	std::string filename;
};

#endif
