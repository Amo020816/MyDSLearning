//
// Created by Amo on 2022/11/7.
//

#include "MergeSorting.h"
#include "InsertSort.h"
#include <iostream>
#include <vector>

using namespace std;
void sortTest() {

    vector<int> vec;

    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(4);

    insertSort(vec);

    std::cout << "Checking.... No more outputs means success.\n";
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1]) {
            std::cout << "Check failed\n";
            break;
        }

}