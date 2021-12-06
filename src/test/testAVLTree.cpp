
#include "AVLTree.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Test AVLTree:" << std::endl;

  AVLTree<int> *t = new AVLTree<int>();

  t->insert(0);

  std::cout << *t << std::endl;

  return 0;
}