#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>

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

        Node (const V& value) : h(1), left(nullptr), right(nullptr), value(value) {}

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

        // friend std::ostream& operator<<(std::ostream& os, const Node& n) {
        //   return os << n.value;
        // }
        //
        // void inOrder(Callback callback) const {
        //   if (left) { left.inOrder(callback); }
        //   callback(value);
        //   if (right) { right.inOrder(callback); }
        // }
        //
        // string toString () {
        //   string result = "" + value;
        //   return result;
        // }
        //
        // string toString() {
        //   string result = "";
        //
        //   if (left != nullptr) {
        //     result += left->toString();
        //   }
        //
        //   for (int i = 0; i < h; i++) {
        //     result += "   ";
        //   }
        //   cout << *this; // DBG
        //   result += "" + value;
        //
        //   if (right != nullptr) {
        //     result += right->toString();
        //   }
        //
        //   return result;
        // }
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

    /**
      * @brief
      * @details description
      *
      * @param root the old root of the sub-tree we want to insert to
      * @return the new root of the sub-tree we inserted the new node to.
      */
    static Node* insert(Node* root, const V& value) {
      if (root == nullptr) { return new Node(value); }

      // Insert
      if (value < *root) {
        root->left = insert(root->left, value);
      } else if (*root < value) {
        root->right = insert(root->right, value);
      } else {
        // We fond the same key
        return nullptr;
      }

      root->updateHight();

      if (root->balance() > 1) {
        // if (value < root->left->value) {
        //   return rightRotate(root);
        // }
        if (value > root->left->value) {
          root->left = leftRotate(root->left);
        }
        return rightRotate(root);
      }

      if (root->balance() < -1 && value < root->right->value) {
        // if (value < root->right->value) {
        //   return leftRotate(root);
        // }
        if (value > root->right->value) {
          root->right = rightRotate(root->right);
        }
        return leftRotate(root);
      }

      return root;
    }

    static Node* remove(Node* root, const V& value) {
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

  public:
    // void (Callback*) (const V& value);

    AVLTree () : size(0), root(nullptr) {}

    ~AVLTree () {
        deleteTree(root);
    }

    Node* find (V& value) {
        Node *tmp = root;
        while(tmp != nullptr) {
            if(value == *(tmp->value)) {
                return tmp;
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
      root = remove(root, value);
      // TODO: size--;
    }

    friend std::ostream& operator<<(std::ostream& os, const AVLTree& t) {
      if (t.root != nullptr) {
        os << *(t.root);
      }
      return os;
    }

    // void inOrder(Callback callback) {
    //   if (root) { root->inOrder(callback); }
    // }

};

#endif