//
// Created by Amo on 2022/10/25.
//

#include "AvlTree.h"
#include <iostream>

using namespace std;

int main() {

    AvlTree<int> avlTree;

    avlTree.insert(2);
    avlTree.insert(1);
    avlTree.insert(3);

    AvlTree<int> avlTree1 = avlTree;

    avlTree.insert(4);
    avlTree.insert(5);
    avlTree.insert(6);
    avlTree.insert(7);+

    avlTree.print(cout);
    avlTree1.print(cout);


    return 0;
}