//
// Created by Amo on 2022/12/3.
//

#ifndef MYDSLEARNING_SHELLSORT_H
#define MYDSLEARNING_SHELLSORT_H

#include <cstddef>
#include <functional>

template<typename Iterator, typename Comparator>
void shellSort(const Iterator arr, size_t size, Comparator cmp) {

    for (size_t gap = size / 2; gap > 0; gap /= 2) {

        for (size_t i = gap; i < size; i++) {
            auto temp = std::move(arr[i]);

            size_t j;
            for (j = i; j >= gap && cmp(temp, arr[j - gap]); j -= gap)
                arr[j] = std::move(arr[j - gap]);

            arr[j] = std::move(temp);
        }
    }
}

template<typename Iterator, typename Comparator>
void shellSort(const Iterator begin, const Iterator end, Comparator cmp) {
    shellSort(begin, end - begin, cmp);
}

template<typename Iterator>
void shellSort(const Iterator begin, const Iterator end) {
    shellSort(begin, end, std::less<decltype(*begin)>{});
}

#endif //MYDSLEARNING_SHELLSORT_H
