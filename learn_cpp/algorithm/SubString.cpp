#include "SubString.h"

#include <iostream>

char g_base_string[] = {"ADOBECODEBANC"};
char g_sub_string[] = {"ABC"};

void calc_substring_by_backtrace(std::string const &base_string, std::string const &sub_string)
{
  std::cout << "start calculate substring by backtrace" << std::endl;
}

void calc_substring(std::string const &base_string, std::string const &sub_string)
{
  std::string base_string_tmp(base_string), sub_string_tmp(sub_string);

  if (!base_string_tmp.empty() && !sub_string_tmp.empty())
  {
    base_string_tmp = std::string(g_base_string);
    sub_string_tmp = std::string(g_sub_string);
  }

  // backtrace algorithm
  calc_substring_by_backtrace(base_string_tmp, sub_string_tmp);
}