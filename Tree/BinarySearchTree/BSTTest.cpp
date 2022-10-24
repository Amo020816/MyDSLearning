//
// Created by Amo on 2022/10/24.
//

#include "BSTree.h"
#include <iostream>

using namespace std;
int main() {
    BinarySearchTree<int> bst1;
    bst1.insert(50);
    bst1.insert(25);
    bst1.insert(100);
    bst1.insert(30);
    bst1.insert(80);
    bst1.insert(60);

    BinarySearchTree<int> bst2;
    bst2 = bst1;

    bst1.remove(50);

    bst1.print(std::cout);
    printf("\n");
    bst2.print(std::cout);

    return 0;
}