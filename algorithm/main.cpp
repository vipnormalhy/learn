#include <iostream>

#include "BlackRedTree/brt.h"

int main()
{
  BRTree<int> tree;

  tree.insert(2);
  tree.insert(1);
  tree.insert(8);
  tree.insert(6);
  tree.insert(3);
  tree.insert(0);
  tree.travel_tree();
  return 0;
}