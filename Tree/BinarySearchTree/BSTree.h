//
// Created by Amo on 2022/10/18.
//

#ifndef MYDSLEARNING_BSTREE_H
#define MYDSLEARNING_BSTREE_H

#include <utility>

// type CT means comparable types
template<typename CT>
class BinarySearchTree {
public:

    BinarySearchTree();

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

    /***/
    void makeEmpty()
};


#endif //MYDSLEARNING_BSTREE_H
