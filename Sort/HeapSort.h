//
// Created by Amo on 2022/12/1.
//

#ifndef MYDSLEARNING_HEAPSORT_H
#define MYDSLEARNING_HEAPSORT_H

#include <utility>
#include <functional>
#include <cstddef>

size_t getLeftChild(size_t index) {
    return index * 2 + 1;
}

template<typename Iterator, typename Comparator>
void percolateDown(const Iterator arr, size_t node,
                   size_t size, Comparator cmp) {
    size_t child;
    typename std::remove_reference< decltype(*arr) >::type temp = arr[node];

    for (; getLeftChild(node) <= size; node = child) {
        child = getLeftChild(node);

        if (child + 1 <= size && cmp(arr[child], arr[child + 1]))
            child++;

        if (cmp(temp, arr[child]))
            arr[node] = std::move(arr[child]);
        else
            break;
    }

    arr[node] = std::move(temp);
}

template<typename Iterator, typename Comparator>
void heapSort(const Iterator arr, size_t size, Comparator cmp) {

    // Build heap.
    for (int i = size / 2 - 1; i >= 0; i--)
        percolateDown(arr, i, size, cmp);


    for (int i = 0; i < size; i++) {
        std::swap(arr[size - i], arr[0]);
        percolateDown(arr, 0, size - i - 1, cmp);
    }
}

template<typename Iterator, typename Comparator>
void heapSort(const Iterator begin, const Iterator end, Comparator cmp) {
    size_t size = end - begin - 1;
    heapSort(begin, size, cmp);
}

template<typename Iterator>
void heapSort(const Iterator begin, const Iterator end) {
    heapSort(begin, end, std::less<decltype(*begin)>{});
}

#endif //MYDSLEARNING_HEAPSORT_H
