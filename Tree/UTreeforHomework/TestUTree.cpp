//
// Created by Amo on 2022/10/27.
//
#include <iostream>

/**
 *  An ugly tree .
 */

/** Basic node structure */
struct TreeNode {
    int element;
    TreeNode * first_child;
    TreeNode * next_sibling;

    TreeNode(int ele, TreeNode * fc, TreeNode * ns)
            : element(ele), first_child(fc), next_sibling(ns) {
        // empty
    }
};

TreeNode * newNode(int ele) {
    return new TreeNode(ele, nullptr, nullptr);
}


/** Add sibling to node. */
TreeNode * addSibling(TreeNode * node, int ele) {
    if (node == nullptr)
        return nullptr;

    while (node->next_sibling != nullptr)
        node = node->next_sibling;

    return (node->next_sibling = newNode(ele));
}

/** Add child to node. */
TreeNode * addChild(TreeNode * node, int ele) {
    if (node == nullptr)
        return nullptr;

    // check if child list is empty.
    if (node->first_child != nullptr)
        addSibling(node->first_child, ele);
    else
        return (node->first_child = newNode(ele));
}

/** Traverse the tree. */
void traverseTree(TreeNode * t) {
    if (t == nullptr)
        return;

    while (t != nullptr) {
        std::cout << t->element << ' ';
        if (t->first_child != nullptr)
            traverseTree(t->first_child);
        t = t->next_sibling;
    }
}

using namespace std;
int main() {
    TreeNode *root =newNode(10);
    addChild(root, 2);
    addChild(root, 3);
    TreeNode *n3  = addChild(root, 4);
    addChild(n3, 6);
    TreeNode *n5  = addChild(root, 5);
    addChild(n5, 7);
    addChild(n5, 8);
    addChild(n5, 9);
    traverseTree(root);
    return 0;
}