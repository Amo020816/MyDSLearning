//
// Created by Amo on 2022/11/12.
//

#include "BinaryHeap.h"
#include <iostream>

using namespace std;

void heapInsertTest() {
    BinaryHeap<int> heap;
    cout << "Checking.." << endl;

    heap.insert(50);
    if (heap.getMin() != 50)
        cout << "Insert error.\n";
}

void heapMultipleInsertTest() {
    BinaryHeap<int> heap;
    cout << "Checking.." << endl;

    for (int i = 100; i >= 0; i--)
        heap.insert(i);

    if (heap.getMin() != 0)
        cout << "Multiple insert error.\n";
}

void heapDeleteTest() {
    BinaryHeap<int> heap;
    cout << "Checking..\n";

    for (int i = 100; i >= 0; i--)
        heap.insert(i);

    for (int i = 0; i < 10; i++) {
        heap.deleteMin();
        if (heap.getMin() != i + 1)
            cout << "Delete error.\n";
    }
}