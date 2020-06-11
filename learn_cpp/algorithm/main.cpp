#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "BlackRedTree/brt.h"
#include "NQueen.h"
#include "Fibonacci.h"
#include "NCoins.h"
#include "BinarySearch.h"
#include "SubString.h"

void test_rbtree()
{
  BRTree<int> tree;

  // int insert_data[] = {1, 10, 9, 2, 3, 8, 7, 4, 5, 6};
  int insert_data[] = {1, 9, 10, 2, 3};
  for (auto i : insert_data)
  {
    tree.insert(i);
  }
  tree.travel_tree();
  // tree.insert(2);
  // tree.insert(1);
  // tree.insert(8);
  // tree.insert(6);
  // tree.insert(3);
  // tree.insert(0);
  // tree.travel_tree();

  // std::this_thread::sleep_for(std::chrono::seconds(10));
}

void test_queen()
{
  int queen_num;
  std::cout << "Please Enter queen count: ";
  std::cin >> queen_num;
  n_queen_entry(queen_num);
}

void test_fibonacci()
{
  int n;
  std::cout << "Please enter fibonacci n:";
  std::cin >> n;
  fibonacci_entry(n);
}

void test_ncoin()
{
  std::vector<int> coins({3, 5, 2, 10});

  int money;
  std::cout << "Input money num: ";
  std::cin >> money;

  ncoins_entry(coins, money);
}

void test_binary_search()
{
  int target;
  std::cout << "Input search target: ";
  std::cin >> target;
  int index = binary_search(target);
  std::cout << "Find index: " << index << std::endl;
  index = binary_search_left_edge(target);
  std::cout << "Find left index: " << index << std::endl;
  index = binary_search_right_edge(target);
  std::cout << "Find right index: " << index << std::endl;
}

int main()
{
  test_queen();
  test_fibonacci();
  test_ncoin();
  test_binary_search();
  calc_substring();

  std::string result;
  while(true)
  {
    std::cout << "Input y/Y to Exit: ";
    std::cin >> result;
    if (result.compare("y") == 0 || result.compare("Y") == 0)
    {
      break;
    }
  }
  return 0;
}