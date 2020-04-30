#pragma once

#include <vector>

std::vector<int> data_vector({1, 3, 5, 7, 9, 10, 11, 12, 12, 12, 12, 12, 12, 12, 15, 17, 19, 31, 33, 35, 39});

int binary_search(int num)
{
  int index = -1;
  int left = 0;
  int right = static_cast<int>(data_vector.size() - 1);

  while(left <= right)
  {
    int mid = left + (right - left) / 2;

    if (data_vector[mid] == num)
    {
      return mid;
    }
    else if (data_vector[mid] > num)
    {
      right = mid - 1;
    }
    else if (data_vector[mid] < num)
    {
      left = mid + 1;
    }
  }

  return index;
}

int binary_search_left_edge(int num)
{
  int index = -1;
  int left = 0;
  int right = static_cast<int>(data_vector.size() - 1);

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (data_vector[mid] == num)
    {
      right = mid;

      if (left == right)
      {
        return left;
      }
    }
    if (data_vector[mid] > num)
    {
      right = mid - 1;
    }
    else if (data_vector[mid] < num)
    {
      left = mid + 1;
    }
  }

  return index;
}