//
// Created by Amo on 2022/11/7.
//

#include "Sort.h"
#include <iostream>
#include <vector>

void sortTest() {

    std::vector<int> vec;
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);

    mergeSort(vec.begin(), vec.end());

    for (auto item : vec) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
    std::less<> defaultComparator;

    std::cout << "Checking.... No more outputs means success.\n";
    for (int i = 0; i < vec.size() - 1; i++)
        if (!defaultComparator(vec[i], vec[i + 1])) {
            std::cout << "Check failed\n";
            break;
        }
}