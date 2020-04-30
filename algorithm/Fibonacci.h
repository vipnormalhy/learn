#pragma once

#include <iostream>
#include <unordered_map>

std::unordered_map<int, long> fibonacci_result;

long start_fibonacci(int n)
{
  if (n == 1 || n == 2)
  {
    return 1;
  }
  else
  {
    long result1, result2;
    if (fibonacci_result.find(n - 1) != fibonacci_result.end())
    {
      result1 = fibonacci_result[n - 1];
    }
    else
    {
      result1 = start_fibonacci(n - 1);
      fibonacci_result[n - 1] = result1;
    }

    if (fibonacci_result.find(n - 2) != fibonacci_result.end())
    {
      result2 = fibonacci_result[n - 2];
    }
    else
    {
      result2 = start_fibonacci(n - 2);
      fibonacci_result[n - 2] = result2;
    }

    return result1 + result2;
  }
}

long start_fibonacci2(int n)
{
  if (n < 2)
  {
    return 1;
  }

  long pre = 1, cur = 1;
  long result;

  for (int index = 2; index < n; index++)
  {
    result = pre + cur;
    pre = cur;
    cur = result;
  }

  return result;
}

void fibonacci_entry(int n)
{
  long result = start_fibonacci(n);
  long result2 = start_fibonacci2(n);
  std::cout << "fibonacci result is " << result << " result2 is " << result2 << std::ends;
  std::cout << "fibonacci has cache " << fibonacci_result.size() << std::endl;
  return;
}