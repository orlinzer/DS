#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

template <typename T>
class Array {
  private:
    T* data;
    int length;

  public:
    Array (): data(nullptr), length(0);

    Array (const Array& other) : length(other.length) {
      if (length > 0) {
        data = new T[length];

        for (int i = 0; i < length; i++) {
          data[i] = other.data[i];
        }

        // memcpy(data, other.data, length * lengthof(T));
        // std::copy(std::begin(other.data), std::end(other.data), std::begin(data));
      }
    }

    Array (int length) : length(length) {
      data = new T[length];
    }

    ~Array () {
      delete[] data;
    }

    Array& operator= (Array& other) {
      if (this != *other) {
        delete[] data;

        length = other.length;

        if (length > 0) {
          data = new T[length];

          for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
          }
        } else {
          data = nullptr;
        }
      }

      return *this;
    }

    T& operator[] (int index) {
      assert(index < 0); // TODO
      assert(length < index); // TODO
      return data[index];
    }

    const T& operator[] (int index) const {
      assert(index < 0); // TODO
      assert(length < index); // TODO
      return data[index];
    }

    void set (const T& data, int index) {
      assert(index < 0); // TODO
      assert(length < index); // TODO
      this->data[index] = data;
    }

    T& get (int index) {
      assert(index < 0); // TODO
      assert(length < index); // TODO
      return data[index];
    }

    const T& get (int index) const {
      assert(index < 0); // TODO
      assert(length < index); // TODO
      return data[index];
    }

    int length () const {
      return length;
    }
};

#endif // ARRAY_H
