//
// Created by Amo on 2022/11/7.
//

#ifndef MYDSLEARNING_MERGESORT_H
#define MYDSLEARNING_MERGESORT_H
#include <functional>
#include <cstddef>
#include <utility>

template<typename Iterator, typename tempIterator,typename Comparator>
void merge(const Iterator & arr, const tempIterator & temp, Comparator cmp,
           size_t leftPos, size_t rightPos, size_t rightEnd) {
    size_t leftEnd = rightPos - 1;
    size_t tempPos = leftPos;
    size_t numberElements = rightEnd - leftPos + 1;

    for (;leftPos <= leftEnd && rightPos <= rightEnd;) {
        if (cmp(*(arr + leftPos), *(arr + rightPos))) {
            // Comparator return true.
            *(temp + tempPos) = std::move(*(arr + leftPos));
            ++tempPos;
            ++leftPos;
        } else {
            // Comparator return false.
            *(temp + tempPos) = std::move(*(arr + rightPos));
            ++tempPos;
            ++rightPos;
        }
    }

    for (;leftPos <= leftEnd;) {
        *(temp + tempPos) = std::move(*(arr + leftPos));
        ++tempPos;
        ++leftPos;
    }

    for (;rightPos <= rightEnd;) {
        *(temp + tempPos) = std::move(*(arr + rightPos));
        ++tempPos;
        ++rightPos;
    }

    for (int i = 0; i < numberElements; i++, rightEnd--)
        *(arr + rightEnd) = std::move(*(temp + rightEnd));
}

/**
 * Internal method of merge sort.
 * @param arr Begin iterator of the array
 * @param temp Begin iterator of the temp array.
 * @param cmp Comparator.
 * @param left left index to sort.
 * @param right right index to sort.
 */
template<typename Iterator, typename tempIterator, typename Comparator>
void mergeSort(const Iterator & arr, const tempIterator & temp, Comparator cmp,
               size_t left, size_t right) {
    if (left < right) {
        size_t mid = (left + right) / 2;
        mergeSort(arr, temp, cmp, left, mid);
        mergeSort(arr, temp, cmp, mid + 1, right);
        merge(arr, temp, cmp, left, mid + 1, right);
    }
}

/**
 * @brief Merge sort an array, inplace the result.
 * @param begin Begin iterator of the sort array.
 * @param end End iterator of the sort array.
 * @param cmp Comparator function.
 */
template<typename Iterator, typename Comparator>
void mergeSort(const Iterator & begin, const Iterator & end, Comparator cmp) {
    const size_t size = end - begin - 1;
    auto * temp = new typename std::remove_reference<decltype(*begin)>::type[size + 4];
    mergeSort(begin, temp, cmp, 0, size);
}

/**
 * @brief Merge sort an array with default less than comparator, inplace the result.
 * @param begin Begin iterator of the sort array.
 * @param end End iterator of the sort array.
 */
template<typename Iterator>
void mergeSort(const Iterator & begin, const Iterator & end) {
    mergeSort(begin, end, std::less<decltype(*begin)>{});
}


#endif //MYDSLEARNING_MERGESORT_H
