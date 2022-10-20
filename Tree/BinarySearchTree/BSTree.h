//
// Created by Amo on 2022/10/18.
//

#ifndef MYDSLEARNING_BSTREE_H
#define MYDSLEARNING_BSTREE_H

#include <iostream>
#include <utility>

// type CT means comparable types
template<typename CT>
class BinarySearchTree {
public:

    BinarySearchTree()
    : root_(nullptr) {
        // empty
    }

    /**
     * Copy constructor
     * */
    BinarySearchTree( const BinarySearchTree & rhs)
    : root_(nullptr) {
        root_ = clone(rhs.root_);
    }

    /**
     * Move constructor
     * */
    BinarySearchTree( BinarySearchTree && rhs)
    : root_(rhs.root_) {
        rhs.root_ = nullptr;
    }

    /**
     * destructor
     */
     ~BinarySearchTree() {
        makeEmpty();
     }

    /**
     * Copy assignment
     * */
    BinarySearchTree & operator =(const BinarySearchTree & rhs) {
        BinarySearchTree copy = rhs;
        std::swap(copy, *this);
        return *this;
    }

    /**
     * Move assignment
     * */
     BinarySearchTree & operator =(BinarySearchTree && rhs) {
         std::swap(rhs.root_, root_);
         rhs.makeEmpty();
         rhs.root_ = nullptr;
         return *this;
     }

     /**
      * Find the smallest element in the tree.
      * */
      const CT & findMin() const {
          if (root_ == nullptr) {
              // throw exception
              std::cout << "root_ is null" << std::endl;
              return;
          }
          return findMin(root_) -> data;
      }

      /**
       * Find the largest element in the tree
       */
      const CT & findMax() const {
          if (root_ == nullptr) {
              // throw exception
              std::cout << "root_ is null\n";
              return;
          }
          return findMax(root_) -> data;
      }

      /**
       * Return true if x is found in the tree
       */
       bool contain(const CT & x) const {
          return contain(x, root_);
       }

      /**
       * Make the tree empty
       */
       void makeEmpty() {
          makeEmpty(root_);
       }





private:
    struct BinaryNode{
        CT data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const CT& d, BinaryNode* l, BinaryNode* r)
        : data(d), left(l), right(r) {
            // empty
        }

        BinaryNode(CT&& d, BinaryNode* l, BinaryNode* r)
        : data(std::move(d), left(l), right(r)) {
            // empty
        }
    };

    BinaryNode* root_;

    /**
     * Internal method to test if an item is in subtree.
     * x is item to search for.
     * t is the node roots the subtree. */
    bool contain( const CT& x, BinaryNode *t) const {
        if (t == nullptr)
            return false;
        else if (x < t->data)
            return contain(x, t->left);
        else if (t->data < x)
            return contain(x, t->right);
        else
            return true;
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     * recursively. */
    BinaryNode * findMin(BinaryNode * t) const{
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     * recursively. */
     BinaryNode * findMax(BinaryNode * t) const {
         if (t == nullptr)
             return nullptr;
         if (t->right == nullptr)
             return t;
         else
             return findMax(t->right);
     }

     /* The non-recursively version of findMin:

     BinaryNode * findMinWithNonRecursive(BinaryNode * t) const {
         if (t != nullptr)
             for (;t->left != nullptr;)
                 t = t->left;
         return t;
     }
    */

    /**
     * Internal method to insert an item x into a subtree t.
     * x is the item to insert.
     * t is the node roots the subtree.
     * Recursively*/
    void insert( const CT& x, BinaryNode * & t) {
        if (t == nullptr)
            t = new BinaryNode(x, nullptr, nullptr);
        if (x < t->data)
            insert(x, t->left);
        else if (x > t->data)
            insert(x, t->right);
        else ; // Already existed.
    }

    /**
     * Internal method to insert an item into a subtree t.
     * x is the item to insert by moving.
     * t is the node roots the subtree.
     * Recursively */
    void insert(CT &&x, BinaryNode * & t) {
        if (t == nullptr)
            t = new BinaryNode(std::move(x), nullptr, nullptr);
        if (x < t->data)
            insert(std::move(x), t->left);
        else if (x > t->data)
            insert(std::move(x), t->right);
        else ; // Already existed.
    }

    /**
     * Internal method to remove an item from a subtree.
     * x is the item to remove.
     * t is the node roots the subtree.
     * Recursively */
    void remove(const CT& x, BinaryNode * & t) {
        if (t == nullptr)
            return;     // Item not found, do nothing.
        if (x < t->data)
            remove(x, t->left);
        else if (x > t->data)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) {
            t->data = findMin(t->right);
            remove(t->data, t->right);
        }
        else {
            BinaryNode *old_node = t;
            t = (t->left == nullptr)? t->right: t->left;
            delete old_node;
        }
    }

    /**
     * Internal method to print subtree in order
     * out is output stream.
     * x is the node roots subtree. */
     void printTree(std::ostream & out, BinaryNode * t) {
        if (t == nullptr)
            return;
        printTree(out, t->left);
        out << t->data << ' ';
        printTree(out, t->right);
     }

    /**
     * Internal method to make subtree empty.
     * t is the node roots subtree. */
    void makeEmpty( BinaryNode * t) {
        if (t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }

    /**
     * Internal method to clone a subtree
     * t is the node roots subtree.
     * */
     BinaryNode * clone(BinaryNode * t) {
        if (t == nullptr)
            return;
        else return new BinaryNode{t->data , clone(t->left), clone(t->right)};
     }
};


#endif //MYDSLEARNING_BSTREE_H
