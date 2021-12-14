
#include "AVLTree.hpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cout << "Test AVLTree:" << endl;

  AVLTree<int> t;

  t.insert(7);
  // cout << t << endl;
  t.insert(0);
  // cout << t << endl;
  t.insert(2);
  // cout << t << endl;
  t.insert(1);
  // cout << t << endl;
  t.insert(5);
  // cout << t << endl;
  t.insert(8);
  // cout << t << endl;
  t.insert(9);
  // cout << t << endl;
  t.insert(3);
  // cout << t << endl;
  t.insert(4);
  // cout << t << endl;
  t.insert(6);
  // cout << t << endl;

  AVLTree<int> t2(t);

  t.remove(2);
  // cout << t << endl;

  t.remove(3);
  // cout << t << endl;

  t.remove(6);
  // cout << t << endl;

  t.remove(1);
  cout << t << endl;
  cout << t2 << endl;


  AVLTree<int> t3(t, t2);
  cout << t3 << endl;

  return 0;
}
