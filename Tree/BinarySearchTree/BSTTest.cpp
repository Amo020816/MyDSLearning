//
// Created by Amo on 2022/10/24.
//

#include "BSTree.h"
#include <iostream>

using namespace std;
int main() {
    BinarySearchTree<int> bst1;
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(4);
    bst1.insert(6);
    bst1.insert(9);
    bst1.insert(2);
    bst1.insert(5);
    bst1.insert(7);
    bst1.remove(3);
    return 0;
}