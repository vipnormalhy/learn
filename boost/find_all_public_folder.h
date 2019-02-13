#pragma once

#include <string>

#include "boost/filesystem.hpp"

class FindProjectIncludeDirectory {
  private:
    boost::filesystem::path m_engine_directory;
    boost::filesystem::path m_project_directory;

    bool set_base_directory(const std::string &path, bool is_engine_dir);
    std::string get_engine_include_directory();
    std::string get_project_include_directory();

  public:
    bool set_unreal_engine_directory(const std::string &path);
    bool set_project_directory(const std::string &path);
    std::string get_include_directory();
};