#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>

template <typename V>
class Trie {
private:
  class Node {
    public:
      string key;
      V value;

      Node

      Node (const string& key, const V& value) : key(key), value(value) {}

      Node (const Node& other) : key(other.key), value(other.value) {}

      ~Node () {}

      Node& operator= (const Node& other) {
        this(other);
      }
  }
public:
  Trie () {}
};

#endif // TRIE_H