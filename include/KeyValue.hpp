
#ifndef KEY_VALUE_H
#define KEY_VALUE_H

#include <iostream>

template <typename K, typename V>
class KeyValue
{
private:
  K key;
  V value;

public:
  KeyValue() : key(), value() {}
  // KeyValue() = default;

  KeyValue(const K &key, const V &value) : key(key), value(value) {}

  // ~KeyValue () {}
  ~KeyValue() = default;

  // KeyValue& operator= (const KeyValue& keyValue) noexcept {
  //   key(keyValue->key);
  //   value(keyValue->value);
  // }
  KeyValue &operator=(const KeyValue &other) = default;

  bool operator==(const KeyValue &other) const noexcept
  {
    return key == other.key;
  }

  bool operator!=(const KeyValue &other) const noexcept
  {
    return key != other.key;
  }

  bool operator<=(const KeyValue &other) const noexcept
  {
    return key <= other.key;
  }

  bool operator<(const KeyValue &other) const noexcept
  {
    return key < other.key;
  }

  bool operator>=(const KeyValue &other) const noexcept
  {
    return key >= other.key;
  }

  bool operator>(const KeyValue &other) const noexcept
  {
    return key > other.key;
  }

  bool operator==(const K &other) const noexcept
  {
    return key == other;
  }

  bool operator!=(const K &other) const noexcept
  {
    return key != other;
  }

  bool operator<=(const K &other) const noexcept
  {
    return key <= other;
  }

  bool operator<(const K &other) const noexcept
  {
    return key < other;
  }

  bool operator>=(const K &other) const noexcept
  {
    return key >= other;
  }

  bool operator>(const K &other) const noexcept
  {
    return key > other;
  }

  friend bool operator==(const K &leftKey, const KeyValue &keyValue) noexcept
  {
    return leftKey == keyValue.key;
  }

  friend bool operator!=(const K &leftKey, const KeyValue &keyValue) noexcept
  {
    return leftKey != keyValue.key;
  }

  friend bool operator<=(const K &leftKey, const KeyValue &keyValue) noexcept
  {
    return leftKey <= keyValue.key;
  }

  friend bool operator<(const K &leftKey, const KeyValue &keyValue) noexcept
  {
    return leftKey < keyValue.key;
  }

  friend bool operator>=(const K &leftKey, const KeyValue &keyValue) noexcept
  {
    return leftKey >= keyValue.key;
  }

  friend bool operator>(const K &leftKey, const KeyValue &keyValue) noexcept
  {
    return leftKey > keyValue.key;
  }

  const V &operator*() const
  {
    return value;
  }

  V &operator*()
  {
    return value;
  }

  friend std::ostream &operator<<(std::ostream &os, const KeyValue &keyValue)
  {
    return os << "(key: " << keyValue.key << ", value: " << keyValue.value << ")";
  }

  K &getKey()
  {
    return key;
  }

  const K &getKey() const
  {
    return key;
  }

  void setKey(const K &key)
  {
    this->key = key;
  }

  V &getValue()
  {
    return value;
  }

  const V &getValue() const
  {
    return value;
  }

  void setValue(const V &value)
  {
    this->value = value;
  }
};

#endif // KEY_VALUE_H
