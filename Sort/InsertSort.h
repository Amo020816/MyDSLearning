//
// Created by Amo on 2022/11/15.
//

#ifndef MYDSLEARNING_INSERTSORT_H
#define MYDSLEARNING_INSERTSORT_H
#include <vector>
#include <utility>

template<typename T>
void insertSort(std::vector<T> & array) {
    for (int i = 0; i < array.size(); i++) {
        T temp = std::move(array[i]);

        int j;
        for (j = i; j > 0 && temp < array[j - 1]; j--) {
            array[j] = std::move(array[j - 1]);
        }

        array[j] = std::move(temp);
    }
}


#endif //MYDSLEARNING_INSERTSORT_H
