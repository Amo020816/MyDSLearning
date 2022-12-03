//
// Created by Amo on 2022/11/21.
//

#ifndef MYDSLEARNING_QUICKSORT_H
#define MYDSLEARNING_QUICKSORT_H

#include <functional>
#include <cstddef>
#include <utility>

template<typename Iterator, typename Comparator>
size_t partition(const Iterator arr, size_t left, size_t right, Comparator cmp) {
    size_t mid = (left + right) / 2;

    if (cmp(arr[mid], arr[left]))
        std::swap(arr[mid], arr[left]);
    if (cmp(arr[right], arr[left]))
        std::swap(arr[right], arr[left]);
    if (cmp(arr[right], arr[mid]))
        std::swap(arr[right], arr[mid]);

    std::swap(arr[mid], arr[right - 1]);
    typename std::remove_reference<decltype(*arr)>::type pivot = arr[right - 1];

    // Begin partitioning.
    size_t i = left, j = right - 1;
    for (;;) {
        while(cmp(arr[++i], pivot));
        while(cmp(pivot, arr[--j]));

        if ( i < j )
            std::swap(arr[i], arr[j]);
        else
            break;
    }

    // Restore the pivot.
    std::swap(arr[i], arr[right - 1]);

    return i;
}

template<typename Iterator, typename Comparator>
void quickSort(const Iterator arr, size_t left, size_t right, Comparator cmp) {
    if (left + 16 <= right) {
        size_t pivotIndex = partition(arr, left, right, cmp);

        quickSort(arr, left, pivotIndex - 1, cmp);
        quickSort(arr, pivotIndex + 1, right, cmp);
    } else
        insertionSort(arr + left, arr + right + 1, cmp);
}

template<typename Iterator, typename Comparator>
void quickSort(const Iterator begin, const Iterator end, Comparator cmp) {
    size_t right = end - begin - 1;
    quickSort(begin, 0, right, cmp);
}

template<typename Iterator>
void quickSort(const Iterator begin, const Iterator end) {
    quickSort(begin, end, std::less<decltype(*begin)>{});
}

#endif //MYDSLEARNING_QUICKSORT_H
