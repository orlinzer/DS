#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <typename V>
class AVLTree {
  private:
    class Node {
      public:
        Node* left;
        Node* right;
        int h;
        V value;

        static void swap (Node& a, Node& b) {
          V tmpValue = a.value;
          a.value = b.value;
          b.value = tmpValue;
        }

        static void swapHights(Node* a, Node* b) {
          int tmp = a->h;
          a->h = b->h;
          b->h = tmp;
        }

        static int getHight (Node* n) {
          if (n == nullptr) { return 0; }
          return n->h;
        }

        int balance () const {
          return getHight(left) - getHight(right);
        }

        Node* getNext() {
          Node* root = this;
          Node* next = root->right;

          while (next != nullptr) {
            root = next;
            next = next->left;
          }

          return root;
        }

        Node* getPreviews() {
          Node* root = this;
          Node* next = root->left;

          while (next != nullptr) {
            root = next;
            next = next->right;
          }

          return root;
        }

        void updateHight() {
          int l = getHight(left);
          int r = getHight(right);

          h = (l < r) ? r : l;

          h += 1;
        }

        Node () : h(1), left(nullptr), right(nullptr), value() {}

        Node (const V& value) : h(1), left(nullptr), right(nullptr), value(value) {}

        Node (const Node& other) : h(1), left(nullptr), right(nullptr), value(other.value) {}

        ~Node () {}

        Node& operator=(Node& other) = default;

        bool operator==(const Node& other) const {
          return value == other.value;
        }

        bool operator<=(const Node& other) const {
          return value <= other.value;
        }

        bool operator<(const Node& other) const {
          return value < other.value;
        }

        bool operator>=(const Node& other) const {
          return value >= other.value;
        }

        bool operator>(const Node& other) const {
          return value > other.value;
        }

        bool operator==(const V& otherValue) const {
          return value == otherValue;
        }

        bool operator<=(const V& otherValue) const {
          return value <= otherValue;
        }

        bool operator<(const V& otherValue) const {
          return value < otherValue;
        }

        bool operator>=(const V& otherValue) const {
          return value >= otherValue;
        }

        bool operator>(const V& otherValue) const {
          return value > otherValue;
        }

        friend bool operator==(const V& leftValue, const Node& right) {
          return leftValue == right.value;
        }

        friend bool operator<=(const V& leftValue, const Node& right) {
          return leftValue <= right.value;
        }

        friend bool operator<(const V& leftValue, const Node& right) {
          return leftValue < right.value;
        }

        friend bool operator>=(const V& leftValue, const Node& right) {
          return leftValue >= right.value;
        }

        friend bool operator>(const V& leftValue, const Node& right) {
          return leftValue > right.value;
        }

        friend std::ostream& operator<<(std::ostream& os, const Node& n) {
          if (n.left != nullptr) {
            os << *(n.left);
          }

          for (int i = 1; i < n.h; i++) {
            os << " ";
          }
          os << n.value << endl;

          if (n.right != nullptr) {
            os << *(n.right);
          }

          return os;
        }
    };

    int size;
    Node* root;

    static void deleteTree(Node* pointer) {
        if(pointer == nullptr){ return; }
        deleteTree(pointer->left);
        deleteTree(pointer->right);
        delete pointer;
    }

    /**
      *
      *      root
      *       / \
      *      /   \
      *     a     b
      *    / \   / \
      *   a1 a2 b1 b2
      *
      *        a
      *       / \
      *      /   \
      *     a1  root
      *          / \
      *         a2  b
      *            / \
      *           b1 b2
      *
      *
      * @brief Rotate right
      * @details Rotate the root node to the right, and the new root will be the left child.
      *
      * @param root the old root to be rotate. the function assumes that the root exist and has a left child.
      * @return the new root. that was the left child.
      */
    static Node* rightRotate (Node* root) {
      Node* tmp = root->left;
      root->left = tmp->right;
      tmp->right = root;

      root->updateHight();
      tmp->updateHight();

      return tmp;
    }

    /**
      * @brief Rotate left
      * @details Rotate the root node to the left, and the new root will be the right child.
      *
      * @param root the old root to be rotate. the function assumes that the root exist and has a right child.
      * @return the new root. that was the right child.
      */
    static Node* leftRotate (Node* root) {
      Node* tmp = root->right;
      root->right = tmp->left;
      tmp->left = root;

      root->updateHight();
      tmp->updateHight();

      return tmp;
    }

    static Node* min(Node* root) {
      if (root == nullptr) { return nullptr; }
      Node* result = root;
      while (result->left != nullptr) {
        result = result->left;
      }
      return result;
    }

    static Node* max(Node* root) {
      if (root == nullptr) { return nullptr; }
      Node* result = root;
      while (result->right != nullptr) {
        result = result->right;
      }
      return result;
    }

    /**
      * @brief
      * @details description
      *
      * @param root the old root of the sub-tree we want to insert to
      * @return the new root of the sub-tree we inserted the new node to.
      */
    static Node* insert (Node* root, const V& value) {
      if (root == nullptr) { return new Node(value); }

      // Insert
      if (value < *root) {
        root->left = insert(root->left, value);
      } else if (*root < value) {
        root->right = insert(root->right, value);
      } else {
        // We fond the same key
        return root;
      }

      root->updateHight();

      if (root->balance() > 1) { // Left Case
        if (root->left->balance() < 0) { // Left Right Case
          root->left = leftRotate(root->left);
        }
        return rightRotate(root);
      }

      if (root->balance() < -1) { // Right Case
        if (root->right->balance() < 0) { // Right Left Case
          root->right = rightRotate(root->right);
        }
        return leftRotate(root);
      }

      return root;
    }

    static Node* remove (Node* root, const V& value) {
      if (root == nullptr) { return nullptr; }

      // Find the node, move it to be leave if needed and delete it
      if (value < *root) {
        root->left = remove(root->left, value);
      } else if (*root < value) {
        root->right = remove(root->right, value);
      } else {
        // Delete the node if it is a leave or have only one child
        if (root->left == nullptr || root->right == nullptr) {
          Node* child = root->left ? root->left : root->right;
          delete root;
          return child;
        } else {
          // Move the node to be a leave
          Node* tmp = root->getNext();
          Node::swap(*root, *tmp);
          root->right = remove(root->right, tmp->value);
        }
      }

      root->updateHight();

      if (root->balance() > 1) { // Left Case
        if (root->left->balance() < 0) { // Left Right Case
          root->left = leftRotate(root->right);
        }
        return rightRotate(root);
      }

      if (root->balance() < -1) { // Right Case
        if (root->right->balance() > 0) { // Right Left Case
          root->right = rightRotate(root->right);
        }
        return leftRotate(root);
      }

      return root;
    }

    static Node* clone (const Node* other) {
      if (other == nullptr) { return nullptr; }
      Node* result = new Node(*other);
      result->left = clone(other->left);
      result->right = clone(other->right);
      result->updateHight();
      return result;
    }

    static Node* createEmpy (int size) { // O(size)
      if (size <= 0) { return nullptr; }

      Node* result = new Node();
      size--;

      int childSize = size / 2;

      if (size % 2 == 0) {
        result->left = createEmpy(childSize);
      } else {
        result->left = createEmpy(childSize + 1);
      }

      result->right = createEmpy(childSize);

      return result;
    }

    static Node* removeMin (Node** n) { // O(log(|n|))
      if (n == nullptr || *n == nullptr) { return nullptr; }

      if ((*n)->left != nullptr) {
        return removeMin(&((*n)->left));
      }

      Node* result = *n;
      *n = (*n)->left;

      return result;
    }

    // XXX
    static Node* removeMin (Node** a, Node** b) { // O(log(|a|) + log(|b|))
      if (a == nullptr || b == nullptr) { return nullptr; }

      cout << "*"; // DBG

      Node* result;
      if (*a == nullptr) {
        if (*b == nullptr) { return nullptr; }
        return removeMin(b);
        // return nullptr; // DBG
      }
      if (*b == nullptr) {
        return removeMin(a);
        // return nullptr; // DBG
      }

      if ((*a)->left != nullptr) {
        // return removeMin(&((*a)->left), b);
        cout << ((*a)->left);
        return nullptr; // DBG
      }
      if ((*b)->left != nullptr) {
        // return removeMin(a, &((*b)->left));
        return nullptr; // DBG
      }

      // XXX
      if (**a < **b) {
        result = *a;
        *a = (*a)->right;
      } else if (**b < **a) {
        result = *b;
        *b = (*b)->right;
      } else {
        result = *b;
        *b = (*b)->right;
        delete result;
        result = *a;
        *a = (*a)->right;
      }
      return result;
    }

    static void combine (Node** a, Node** b, Node* result) {
      if (result == nullptr) { return; }

      combine(a, b, result->left);

      Node* min = removeMin(a, b);
      if (min == nullptr) { return; }

      result->value = min->value;
      delete min;

      combine(a, b, result->right);
    }

  public:
    // void (Callback*) (const V& value);

    AVLTree () : size(0), root(nullptr) {}

    AVLTree (const AVLTree& other) : size(other.size) {
      root = clone(other.root);
    }

    AVLTree (AVLTree& a, AVLTree& b) : size(a.size + b.size) {
      root = createEmpy(size);

      combine(&(a.root), &(a.root), root);

      a.size = 0;
      b.size = 0;
    }

    ~AVLTree () {
        deleteTree(root);
    }

    V* find (V& value) {
        Node *tmp = root;
        while(tmp != nullptr) {
            if(value == *(tmp->value)) {
                return &(tmp->value);
            }else if(value < *(tmp->value)){
                tmp = tmp->left;
            }else {
                tmp = tmp->right;
            }
        }
        return nullptr;
    }

    void insert (const V& value) {
      root = insert(root, value);
      if (root != nullptr) { size++; }
    }

    void remove (const V& value) {
      if (root == nullptr) { return; }

      Node* newRoot = remove(root, value);
      if (newRoot == nullptr && size != 1) { return; }

      root = newRoot;
      size--;

    }

    friend std::ostream& operator<<(std::ostream& os, const AVLTree& t) {
      if (t.root != nullptr) {
        os << *(t.root);
      }
      return os;
    }

    V* min() {
      Node* result = min(root);
      if (result == nullptr) { return nullptr; }
      return &(result->value);
    }

    V* max() {
      Node* result = max(root);
      if (result == nullptr) { return nullptr; }
      return &(result->value);
    }

    // void inOrder(Callback callback) {
    //   if (root) { root->inOrder(callback); }
    // }

};

#endif