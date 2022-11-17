//
// Created by Amo on 2022/11/7.
//

#ifndef MYDSLEARNING_MERGESORTING_H
#define MYDSLEARNING_MERGESORTING_H
#include <vector>
#include <cstddef>
#include <utility>

template<typename T>
void merge(std::vector<T> & array, std::vector<T> & tempArray, size_t left, size_t right, size_t rightEnd) {
    size_t leftEnd = right - 1;
    size_t tempPos = left;
    size_t numOfElements = rightEnd - left + 1;

    size_t leftPos, rightPos;
    for (leftPos = left, rightPos = right; leftPos <= leftEnd && rightPos <= rightEnd;) {
        if (array[leftPos] < array[rightPos])
            tempArray[tempPos++] = std::move(array[leftPos++]);
        else
            tempArray[tempPos++] = std::move(array[rightPos++]);
    }

    for (;leftPos <= leftEnd;)
        tempArray[tempPos++] = std::move(array[leftPos++]);

    for (;rightPos <= rightEnd;)
        tempArray[tempPos++] = std::move(array[rightPos++]);

    for (int i = 0; i < numOfElements; i++)
        array[left + i] = std::move(tempArray[left + i]);

}


/** Internal method that makes recursive calls.
 * @param array an array of Comparable items.
 * @param tempArray the work array.
 */
template<typename T>
void mergeSort(std::vector<T> & array, std::vector<T> & tempArray, size_t left, size_t right) {
    if (left < right) {
        size_t mid = (left + right) / 2;

        mergeSort(array, tempArray, left, mid);
        mergeSort(array, tempArray, mid + 1, right);
        merge(array, tempArray, left, mid + 1, right);
    }
}

template<typename T>
void mergeSort( std::vector<T> & array) {
    std::vector<T> tempArray(array.size());
    mergeSort(array, tempArray, 0, array.size() - 1);
}



#endif //MYDSLEARNING_MERGESORTING_H
