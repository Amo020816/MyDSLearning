//
// Created by Amo on 2022/11/12.
//

#include "BinaryHeap.h"
#include <chrono>
#include <iostream>
#include <random>

using namespace std;

void heapSortedInputTest() {
    BinaryHeap<int> insertHeap;

    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 100000000; i++)
        insertHeap.insert(i);
    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time difference = " << duration << endl;

    vector<int> array;
    for (int i = 0; i < 100000000; i++)
        array.push_back(i);

    start = chrono::steady_clock::now();
    BinaryHeap<int> linearHeap(array);
    end = chrono::steady_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time difference = " << duration << endl;
}

void heapReverseOrderedTest() {
    BinaryHeap<int> insertHeap;

    auto start = chrono::steady_clock::now();
    for (int i = 100000000; i >= 0 ; i--)
        insertHeap.insert(i);
    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time difference = " << duration << endl;

    vector<int> array;
    for (int i = 100000000; i >= 0 ; i--)
        array.push_back(i);

    start = chrono::steady_clock::now();
    BinaryHeap<int> linearHeap(array);
    end = chrono::steady_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time difference = " << duration << endl;
}

void heapRandomInputTest() {
    vector<int> array;
    srand(time(NULL));
    for (int i = 0; i < 100000000; i++) {
        int randNum = rand() % 100000000;
        array.push_back(randNum);
    }

        BinaryHeap<int> insertHeap;

        auto start = chrono::steady_clock::now();
        for (int i = 0; i < 100000000; i++)
            insertHeap.insert(array[i]);
        auto end = chrono::steady_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Time difference = " << duration << endl;

        start = chrono::steady_clock::now();
        BinaryHeap<int> linearHeap(array);
        end = chrono::steady_clock::now();

        duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Time difference = " << duration << endl;
}