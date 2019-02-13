// Purpose: work through unreal project directory recursively
//          and find out all the public include directories
//          Example: find_public_dir.exe c:/UnrealTestGame
#include <iostream>
#include <string>
#include <fstream>

#include "find_all_public_folder.h"

std::string filter_path(const char *path) {
    if (!path) {
        return "";
    }

    std::string path_str(path);
    size_t len = path_str.length();

    // erase the last " or '
    char last_chr = path_str[len - 1];
    if (last_chr == '"' || last_chr == '\'') {
        path_str.erase(len - 1);
    }

    // erase the first " or '
    char first_chr = path_str[0];
    if (first_chr == '"' || first_chr == '\'') {
        path_str.erase(0, 1);
    }

    return path_str;
}

int main(int argc, const char **argv) {
    if (argc != 3) {
        std::cout << "Parameters Error" << std::endl;
        std::cout << "Example: " << std::endl;
        std::cout << "  find_public_dir.exe c:/unrealengine c:/projectpath" << std::endl;
        return 0;
    }

    std::string engine_path(filter_path(argv[1]));
    std::string project_path(filter_path(argv[2]));

    FindProjectIncludeDirectory find_obj;
    if (!find_obj.set_unreal_engine_directory(engine_path)) {
        std::cout << "Cannot set engine directory" << std::endl;
        return -1;
    } else {
        std::cout << "Set engine directory: " << engine_path << std::endl;
    }

    if (!find_obj.set_project_directory(project_path)) {
        std::cout << "Cannot set project directory" << std::endl;
        return -1;
    } else {
        std::cout << "Set project directory: " << project_path << std::endl;
    }

    std::string include_directory(find_obj.get_include_directory());
    std::ofstream outfile("include_directory.txt", std::ios::out);
    outfile << include_directory;
    outfile.close();

    return 0;
}