//
// Created by Amo on 2022/10/24.
//

#ifndef MYDSLEARNING_AVLTREE_H
#define MYDSLEARNING_AVLTREE_H

#include <utility>
#include <iostream>
#include <algorithm>

template<typename CT>
class AvlTree {
private:

    /**
     * Basic Avl Tree node structure
     */
    struct AvlNode {
        CT data;
        AvlNode * left;
        AvlNode * right;
        int height;

        AvlNode(const CT & d, AvlNode * l, AvlNode * r, int h = 0)
        : data(d), left(l), right(r), height(h) {
            // empty
        }

        AvlNode(CT && d, AvlNode * l, AvlNode * r, int h = 0)
                : data(std::move(d)), left(l), right(r), height(h) {
            // empty
        }
    };

public:
    // interfaces

    AvlTree() : root_(nullptr) {
        // empty
    }

    ~AvlTree() {
        makeEmpty();
        root_ = nullptr;
    }

    AvlTree(const AvlTree & rhs)
    : root_(nullptr) {
        root_ = clone(rhs.root_);
    }

    AvlTree(AvlTree && rhs) noexcept
    : root_(rhs.root_) {
        rhs.root_ = nullptr;
    }

    AvlTree & operator =(const AvlTree & rhs) {
        if (this == &rhs)
            return *this;

        AvlTree copy = rhs;
        std::swap(copy, *this);
        return *this;
    }

    AvlTree & operator =(AvlTree && rhs) noexcept {
        if (*this == rhs)
            return *this;

        makeEmpty();
        root_ = std::exchange(rhs.root_, nullptr);
        return *this;
    }

    /**
     * Judge whether object is in subtree
     * @param data the object to find
     * @return true if data is in the tree
     */
    bool isContain(const CT & data) {
        return isContain(data, root_);
    }

    /**
     * Find the max object in tree.
     * @return const reference of maximum.
     */
    const CT & findMax() {
        return findMax(root_)->data;
    }

    /**
    * Find the maximum of tree
    * @return a constant reference of maximum
    */
    const CT & findMax() const {
        return findMax(root_)->data;
    }

    /**
     * Insert data into tree
     * @param data the object to insert
     */
    void insert(const CT & data) {
        insert(data, root_);
    }

    /**
     * Insert data into tree
     * @param data the object to insert with move
     */
    void insert(CT && data) {
        insert(std::move(data), root_);
    }

    /**
     * remove data from tree
     * @param data the object desired to remove
     */
    void remove(const CT & data) {
        remove(data, root_);
    }

    /**
     * print tree in order
     * @param out an ostream
     */
    void print(std::ostream & out) {
        print(out, root_);
    }

    /**
     * Check if this tree is empty
     * @return true if root_ points to null
     */
    bool isEmpty() {
        return root_ == nullptr;
    }

    /**
     *  Make this tree empty
     */
    void makeEmpty() {
        makeEmpty(root_);
    }


private:
    // internal helper functions

    /**
     * Internal method to judge whether data is in subtree.
     * @param data the object to find.
     * @param t node roots subtree.
     * @return true if data is in subtree.
     */
    bool isContain(const CT & data, AvlNode * t) {
        if (t == nullptr)   // not found
            return false;
        else if (data < t->data)
            return isContain(data, t->left);
        else if (data > t->data)
            return isContain(data, t->right);
        else // found
            return true;
    }

    /**
     * Internal method to get the height of node.
     * @param t An AvlNode on tree.
     * @return the height of the node.
     */
    int getHeight(AvlNode * t) {
        return t == nullptr ? -1: t->height;
    }

    int max(int lhs, int rhs) const {
        return lhs > rhs? lhs: rhs;
    }

    AvlNode * findMin(AvlNode * t) const {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    AvlNode * findMax(AvlNode * t) const {
        if (t == nullptr)
            return nullptr;
        if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    /**
     * Internal method to rotate t from left.
     * Update height and then set new root.
     * @param t Node that needs to rotate.
     */
    void rotateFromLeft(AvlNode * & t) {
        AvlNode * left_child = t->left;
        t->left = left_child->right;
        left_child->right = t;

        // update height
        t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
        left_child->height = max(getHeight(left_child->left), t->height) + 1;

        // set new root
        t = left_child;
    }

    /**
     * Internal method to rotate t from right.
     * Update height and then set new root.
     * @param t Node the needs to rotate.
     */
    void rotateFromRight(AvlNode * & t) {
        AvlNode * right_child = t->right;
        t->right = right_child->left;
        right_child->left = t;

        // update heights.
        t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
        right_child->height = max(getHeight(right_child->right), t->height) + 1;

        // set new root.
        t = right_child;
    }

    /**
     * Internal method to do double rotation from left on t.
     * @param t Node that needs to do double rotation.
     */
    void doubleRotationFromLeft(AvlNode * & t) {
        rotateFromRight(t->left);
        rotateFromLeft(t);
    }

    /**
     * Internal method to do double rotation from right on t.
     * @param t Node that needs to do double rotation.
     */
    void doubleRotationFromRight(AvlNode * & t) {
        rotateFromLeft(t->right);
        rotateFromRight(t);
    }

    /**
     * Internal method to balance t.
     * @param t Node needs to balance.
     */
    void balance(AvlNode * & t) {
        if (t == nullptr)
            return;

        if (getHeight(t->left) - getHeight(t->right) > ALLOWED_IMBALANCE) {
            if (getHeight(t->left->left) >= getHeight(t->left->right))
                rotateFromLeft(t);
            else
                doubleRotationFromLeft(t);
        }

        if (getHeight(t->right) - getHeight(t->left) > ALLOWED_IMBALANCE) {
            if (getHeight(t->right->right) >= getHeight(t->right->left))
                rotateFromRight(t);
            else
                doubleRotationFromRight(t);
        }

        t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
    }

    /**
     * Internal method to insert data into subtree.
     * @param data an object needs to be inserted.
     * @param t node roots subtree.
     */
    void insert(const CT & data, AvlNode * & t) {
        if (t == nullptr)
            t = new AvlNode(data, nullptr, nullptr);
        else if (data < t->data)
            insert(data, t->left);
        else if (data > t->data)
            insert(data, t->right);

        balance(t);
    }

    /**
     * Internal method to insert a r-value data into subtree.
     * @param data a r-value object needs to be inserted.
     * @param t node roots subtree.
     */
    void insert(CT && data, AvlNode * & t) {
        if (t == nullptr)
            t = new AvlNode(std::move(data), nullptr, nullptr);
        else if (data < t->data)
            insert(std::move(data), t->left);
        else if (data > t->data)
            insert(std::move(data), t->right);

        balance(t);
    }

    /**
     * Internal method to remove a data from subtree.
     * @param data the object needs to be removed
     * @param t node roots subtree
     */
    void remove(const CT & data, AvlNode * & t) {
        if (t == nullptr)   // item not found
            return;

        if (data < t->data)
            remove(data, t->left);
        else if (data > t->data)
            remove(data, t->right);
        else if (t->left != nullptr && t->right != nullptr) {
            t->data = findMin(t->right);
            remove(t->data, t->right);
        }
        else {
            AvlNode * old_node = t;
            t = t->left == nullptr? t->right: t->left;
            delete old_node;
        }

        balance(t);
    }

    /**
     * Internal method to make subtree empty.
     * @param t node roots subtree.
     */
    void makeEmpty(AvlNode * t) {
        if (t == nullptr)
            return;

        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }

    /**
     * Internal method to print subtree in order.
     */
    void print(std::ostream & out, AvlNode * t) {
         if (t == nullptr)
             return;

        print(out, t->left);
        out << "data: " << t->data << "  with height " << t->height << std::endl;
        print(out, t->right);
    }

     /**
      * Internal method to clone subtree
      */
     AvlNode * clone(AvlNode * t) {
         if (t == nullptr)
             return nullptr;
         else
             return new AvlNode(t->data, clone(t->left), clone(t->right), t->height);
     }

private:
    // data members
    AvlNode * root_;

    static const int ALLOWED_IMBALANCE = 1;
};

#endif //MYDSLEARNING_AVLTREE_H
