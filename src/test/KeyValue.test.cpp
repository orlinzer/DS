
#include "KeyValue.hpp"

#include <iostream>

#include <cassert>

void testKeyValue_emptyConstructor_call_KeyValue()
{
  KeyValue<int, int> kv;

  std::cout << kv << std::endl;
}

int main(int argc, char *argv[])
{
  std::cout << "Test KeyValue:" << std::endl;
  testKeyValue_emptyConstructor_call_KeyValue();

  return 0;
}