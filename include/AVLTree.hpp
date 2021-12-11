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
          int l = getHight(left);
          int r = getHight(right);
          if (l < r) {
            h = r;
          } else {
            h = l;
          }
          h += 1;
        }

        Node (const V& value) : h(1), left(nullptr), right(nullptr), value(value) {}

        ~Node () {}

        Node& operator=(Node& other) = default;

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

        // friend std::ostream& operator<<(std::ostream& os, const Node& n) {
        //   return os << n.value;
        // }

        friend std::ostream& operator<<(std::ostream& os, const Node& n) {

          // cout << n.value; // DBG

          if (n.left != nullptr) {
            os << *(n.left) << endl;
          }

          for (int i = 0; i < n.h; i++) {
            os << "   ";
          }
          os << n.value << endl; // DBG

          if (n.right != nullptr) {
            os << *(n.right) << endl;
          }

          return os;
        }

        // void inOrder(Callback callback) const {
        //   if (left) { left.inOrder(callback); }
        //   callback(value);
        //   if (right) { right.inOrder(callback); }
        // }

        // string toString () {
        //   string result = "" + value;
        //   return result;
        // }


        // string toString() {
        //   string result = "";

        //   if (left != nullptr) {
        //     result += left->toString();
        //   }

        //   for (int i = 0; i < h; i++) {
        //     result += "   ";
        //   }
        //   cout << *this; // DBG
        //   result += "" + value;

        //   if (right != nullptr) {
        //     result += right->toString();
        //   }

        //   return result;
        // }

        // static void
    };

    int size;

    Node* root;

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
    static Node* rightRotate (Node* root) {
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
    static Node* leftRotate (Node* root) {
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
      * @return the new root of the sub-tree we inserted the new node to.
      */
    static Node* insert(Node* root, const V& value) {
      if (root == nullptr) { return new Node(value); }

      // Insert
      if (value < *root) {
        root->left = insert(root->left, value);

        root->updateHight();
        if (root->balance() > 1) {
          return rightRotate(root);
        }
      } else if (*root < value) {
        root->right = insert(root->right, value);
        root->updateHight();
        if (root->balance() < -1) {
          return leftRotate(root);
        }

      } else {
        // We fond the same key
        return nullptr;
      }

      return root;
    }

    static Node* remove(Node* root, const V& value) {
      if (root == nullptr) { return nullptr; }

      if (value < *root) {
        root->left = remove(root->left, value);
      } else if (*root < value) {
        root->right = remove(root->right, value);
      } else {
        // remove
        if (root->left == nullptr ||
            root->right == nullptr) {

          Node* tmp = root->left ?
                      root->left :
                      root->right;

          // No child case
          if (tmp == NULL)
          {
              tmp = root;
              root = nullptr;
          } else {
            *root = *tmp; // Copy the contents of
                           // the non-empty child
          }

          delete tmp;
        } else {
          // node with two children: Get the inorder
          // successor (smallest in the right subtree)
          Node* tmp = root->getNext();
          Node::swap(*root, *tmp);

          root->right = remove(root->right, tmp->value);
        }

        // If the tree had only one node
        // then return
        if (root == nullptr) { return root; }

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root->updateHight();
        // root->height = 1 + max(height(root->left),
        //                       height(root->right));

        // STEP 3: GET THE BALANCE FACTOR OF
        // THIS NODE (to check whether this
        // node became unbalanced)
        // int balance = getBalance(root);

        // If this node becomes unbalanced,
        // then there are 4 cases

        // Left Left Case
        if (root->balance() > 1 &&
          root->left->balance() >= 0) {
          return rightRotate(root);
        }

        // Left Right Case
        if (root->balance() > 1 &&
          root->left->balance() < 0) {
          root->left = leftRotate(root->left);
          return rightRotate(root);
        }

        // Right Right Case
        if (root->balance() < -1 &&
          root->right->balance() <= 0) {
          return leftRotate(root);
        }

        // Right Left Case
        if (root->balance() < -1 &&
          root->right->balance() > 0) {
          root->right = rightRotate(root->right);
          return leftRotate(root);
        }
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

    // void insert (const V& value) {
    //   insert(new Node(value));
    // }

    void remove (const V& value) {
      if (root == nullptr) { return; }
      root = remove(root, value);
      // TODO: size--;
    }

    friend std::ostream& operator<<(std::ostream& os, const AVLTree* t) {
      return os << *t;
    }

    friend std::ostream& operator<<(std::ostream& os, const AVLTree& t) {
      // os << "[";
      if (t.root != nullptr) {
        os << *(t.root);
        // os << t.root->toString();
      }
      // return os << "]";
      return os;
    }

    // void inOrder(Callback callback) {
    //   if (root) { root->inOrder(callback); }
    // }

};

#endif