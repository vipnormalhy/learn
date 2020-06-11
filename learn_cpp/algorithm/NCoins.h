#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

int calc_ncoins(std::vector<int> &coins, int amount)
{
  int result = -1;
  int choose_coin = -1;

  for (auto const &coin : coins)
  {
    int left_amount = amount - coin;
    // find a solution
    if (left_amount == 0)
    {
      return 1;
    }
    else if (left_amount > 0)
    {
      // find a minimizal solution
      int one_solution = calc_ncoins(coins, left_amount) + 1;

      if (one_solution > 0)
      {
        // find a new solution
        if (result > 0 && one_solution < result)
        {
          result = one_solution;
          choose_coin = coin;
        }
        else if (result < 0)
        {
          result = one_solution;
          choose_coin = coin;
        }
      }
    }
  }

  return result;
}

void ncoins_entry(std::vector<int> &coins, int amount)
{
  int result = calc_ncoins(coins, amount);
  std::cout << "need min coins: " << result << std::endl;
  return;
}