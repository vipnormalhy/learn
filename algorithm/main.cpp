#include <iostream>
#include <thread>
#include <chrono>

#include "BlackRedTree/brt.h"

int main()
{
  BRTree<int> tree;

  // int insert_data[] = {1, 10, 9, 2, 3, 8, 7, 4, 5, 6};
  int insert_data[] = {1, 10, 9};
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

  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}