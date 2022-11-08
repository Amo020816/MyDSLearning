//
// Created by Amo on 2022/11/7.
//

#include "MergeSorting.h"
#include <iostream>
#include <vector>

using namespace std;
int main() {

    vector<int> vec;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    mergeSort(vec);

    for (auto & x : vec)
        cout << x << " ";

    return 0;
}