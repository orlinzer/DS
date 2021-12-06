#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

int MAX (int a, int b) {
  if (a < b) {
    return b;
  }
  return a;
}

template <typename V>
class AVLTree {
  public:
    class Node {
      private:
      public:
        Node* left;
        Node* right;

        int h;

        V* value;

        static void swap (Node& a, Node& b) {
          V* tmpValue = a.value;
          a.value = b.value;
          b.value = tmpValue;
        }

        static void swapHights(Node* a, Node* b) {
          int tmp = a->h;
          a->h = b->h;
          b->h = tmp;
        }

        int balance () const {
          return getHight(left) - getHight(right);
        }

        Node* getNext() const {
          Node* root = this;
          Node* next = root->right;

          while (next != nullptr) {
            root = next;
            next = next->left;
          }

          return root;
        }

        Node* getPreviews() const {
          Node* root = this;
          Node* next = root->left;

          while (next != nullptr) {
            root = next;
            next = next->right;
          }

          return root;
        }

        void updateHight() {
          h = MAX(getHight(left), getHight(right)) + 1;
        }

        Node (const V& value) : h(1), left(nullptr), right(nullptr) {
            this->value = new V(value);
        }

        ~Node () {
          delete value;
        }

        Node& operator=(Node& other) {
          if (value == other.value) { return *this; }

          delete value;

          value = other.value;

          return *this;
        }

        static int getHight (Node* n) {
          if (n == nullptr) { return 0; }
          return n->h;
        }

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
          return leftValue == right->value;
        }

        friend bool operator<=(const V& leftValue, const Node& right) {
          return leftValue <= right->value;
        }

        friend bool operator<(const V& leftValue, const Node& right) {
          return leftValue < right->value;
        }

        friend bool operator>=(const V& leftValue, const Node& right) {
          return leftValue >= right->value;
        }

        friend bool operator>(const V& leftValue, const Node& right) {
          return leftValue > right->value;
        }

        friend std::ostream& operator<<(std::ostream& os, const Node& n) {
          return os << n.value;
        }
    };

  private:

    Node* min;
    Node* max;
    int size;

    Node *root;

    void deleteTree(Node* pointer) {
        if(pointer == nullptr){ return; }
        deleteTree(pointer->left);
        deleteTree(pointer->right);
        delete pointer;
    }

    /**
      * @brief Rotate right
      * @details Rotate the root node to the right, and the new root will be the left child.
      *
      * @param root the old root to be rotate. the function assumes that the root exist and has a left child.
      * @return the new root. that was the left child.
      */
    static Node* RightRotate (Node* root) {
      Node* tmp = root->left;
      root->left = tmp->right;
      tmp->right = root;

      Node::swapHights(tmp, root);

      return tmp;
    }

    /**
      * @brief Rotate left
      * @details Rotate the root node to the left, and the new root will be the right child.
      *
      * @param root the old root to be rotate. the function assumes that the root exist and has a right child.
      * @return the new root. that was the right child.
      */
    static Node* LeftRotate (Node* root) {
      Node* tmp = root->right;
      root->right = tmp->left;
      tmp->left = root;

      Node::swapHights(tmp, root);

      return tmp;
    }

    /**
      * @brief
      * @details description
      *
      * @param root the old root of the sub-tree we want to insert to
      * @param new_node the new node to be inserted
      * @return the new root of the sub-tree we inserted the new node to.
      */
    static Node* insert(Node* root, Node* new_node) {
      if (root == nullptr) { return new_node; }

      // Insert
      if (new_node < root) {
        root->left = insert(root->left, new_node);
        root->updateHight();
        if (root->balance() > 1) {
          return RightRotate(root);
        }
      } else if (root < new_node) {
        root->right = insert(root->right, new_node);
        root->updateHight();
        if (root->balance() < 1) {
          return LeftRotate(root);
        }
      } else {
        // TODO: Check with your teachers what to do
        return nullptr;
      }

      return root;
    }

    static Node* remove(Node* root, V& value) {
      if (root == nullptr) { return nullptr; }

      if (value < root) {
        root->left = remove(root->left, value);
      } else if (root < value) {
        root->right = remove(root->right, value);
      } else {
        // remove
        if (root->left != nullptr) {
          Node* tmp = root->getNext();
          Node:swap(root, tmp);
        }
      }
    }

  public:
    AVLTree () : min(nullptr), max(nullptr), size(0), root(nullptr) {}

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

    void insert (Node* new_node) {
      root = insert(root, new_node);
      if (root != nullptr) { size++; }
    }

    void insert (const V& value) {
      insert(new Node(value));
    }

    void remove (const V& value) {
      // Node* removed
    }

    friend std::ostream& operator<<(std::ostream& os, const AVLTree* t) {
      return os << *t;
    }

    friend std::ostream& operator<<(std::ostream& os, const AVLTree& t) {
      os << "[";
      if (t.root != nullptr) {
        os << t.root;
      }
      return os << "]";
    }
};

#endif