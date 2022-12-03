//
// Created by Amo on 2022/11/28.
//

#include "QuickUnion.h"

QuickUnion::QuickUnion(int numOfElem) {
    parent = new int[numOfElem];
    memset(parent, -1, sizeof(int) * numOfElem );
}

/**
 * Connect the sets of two elements.
 * @param obj1 object 1.
 * @param obj2 object 2.
 */
void QuickUnion::connect(int obj1, int obj2) {
    int root1 = getRoot(obj1), root2 = getRoot(obj2);

    // Compare the weights of two sets.
    if (parent[root1] < parent[root2]) {
        // The weight of root1 is greater than root2.
        parent[root1] += parent[root2];
        parent[root2] = root1;
    } else {
        parent[root2] += parent[root1];
        parent[root1] = root2;
    }
}

bool QuickUnion::isConnect(int obj1, int obj2) {
    return getRoot(obj1) == getRoot(obj2);
}

int QuickUnion::getRoot(int obj) {
    int root = obj;
    for (;parent[root] >= 0;) {
        root = parent[root];
    }

    // Path compression.
    int itr = obj, next;
    for (;parent[itr] >= 0;) {
        next = parent[itr];
        parent[itr] = root;
        itr = next;
    }

    return root;
}




