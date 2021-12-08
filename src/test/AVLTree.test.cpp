
#include "AVLTree.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Test AVLTree:" << std::endl;

  AVLTree<int> t;

  t.insert(0);
  t.insert(1);

  std::cout << t << std::endl;

  return 0;
}
