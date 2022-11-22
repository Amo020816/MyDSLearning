//
// Created by Amo on 2022/11/15.
//

#ifndef MYDSLEARNING_INSERTIONSORT_H
#define MYDSLEARNING_INSERTIONSORT_H
#include <vector>
#include <utility>

template<typename iterator, typename comparator>
void insertionSort(const iterator & begin, const iterator & end, comparator cmp) {
    if (begin == end)
        return;

    iterator j;
    for (iterator i = begin; i != end; i++) {
        auto temp = std::move(*i);

        for (j = i; j != begin && cmp(temp, *(j - 1)); j--) {
            *j = std::move(*(j - 1));
        }

        *j = std::move(temp);
    }
}

template<typename iterator>
void insertionSort(const iterator & begin, const iterator & end) {
    insertionSort(begin, end, std::less<decltype(*begin)>{});
}

#endif //MYDSLEARNING_INSERTIONSORT_H
