
#include "AVLTree.hpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  std::cout << "Test AVLTree:" << std::endl;

  AVLTree<int> t;

  t.insert(7);
  t.insert(0);
  t.insert(2);
  t.insert(1);
  t.insert(5);
  t.insert(8);
  t.insert(9);
  t.insert(3);
  t.insert(4);
  t.insert(6);

  std::cout << t << std::endl;

  t.remove(2);

  std::cout << t << std::endl;

  t.remove(3);

  std::cout << t << std::endl;

  t.remove(6);

  std::cout << t << std::endl;

  t.remove(1);

  std::cout << t << std::endl;

  return 0;
}
