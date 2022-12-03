//
// Created by Amo on 2022/11/28.
//

#ifndef MYDSLEARNING_QUICKUNION_H
#define MYDSLEARNING_QUICKUNION_H

#include <vector>
/**
 * Disjoint Set class.
 * QuickUnion. Use union by weight and path compression.
 * Element in the set are initialized by -1.
 */
class QuickUnion {

public:
    explicit QuickUnion(int numOfElem);

    void connect(int obj1, int obj2);
    bool isConnect(int obj1, int obj2);
    int getRoot(int obj);


private:
    int * parent;
};

#endif //MYDSLEARNING_QUICKUNION_H
