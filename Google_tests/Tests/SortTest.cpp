//
// Created by Amo on 2022/11/22.
//

#include "gtest/gtest.h"
#include "../../Sort/Sort.h"
#include <vector>
#include <random>
#include <chrono>

TEST(TestMergeSort, BasicTest) {
    std::vector<int> sortArr, correctArr;
    sortArr.push_back(9);
    sortArr.push_back(8);
    sortArr.push_back(7);
    sortArr.push_back(6);

    correctArr.push_back(9);
    correctArr.push_back(8);
    correctArr.push_back(7);
    correctArr.push_back(6);

    std::sort(correctArr.begin(), correctArr.end());
    mergeSort(sortArr.begin(), sortArr.end());

    ASSERT_EQ(correctArr, sortArr);
}

TEST(TestInsertionSort, BasicSort) {
    std::vector<int> sortArr, correctArr;
    sortArr.push_back(9);
    sortArr.push_back(8);
    sortArr.push_back(7);
    sortArr.push_back(6);

    correctArr.push_back(9);
    correctArr.push_back(8);
    correctArr.push_back(7);
    correctArr.push_back(6);

    std::sort(correctArr.begin(), correctArr.end());
    insertionSort(sortArr.begin(), sortArr.end());

    ASSERT_EQ(correctArr, sortArr);
}

TEST(TestQuickSort, BasicSort) {
    std::vector<int> sortArr, correctArr;
    sortArr.push_back(9);
    sortArr.push_back(8);
    sortArr.push_back(7);
    sortArr.push_back(6);
    sortArr.push_back(5);
    sortArr.push_back(4);
    sortArr.push_back(3);

    correctArr.push_back(9);
    correctArr.push_back(8);
    correctArr.push_back(7);
    correctArr.push_back(6);
    correctArr.push_back(5);
    correctArr.push_back(4);
    correctArr.push_back(3);

    std::sort(correctArr.begin(), correctArr.end());
    quickSort(sortArr.begin(), sortArr.end());

    ASSERT_EQ(correctArr, sortArr);
}

TEST(TestHeapSort, BasicTest) {
    std::vector<int> sortArr, correctArr;
    sortArr.push_back(9);
    sortArr.push_back(8);
    sortArr.push_back(7);
    sortArr.push_back(6);
    sortArr.push_back(5);
    sortArr.push_back(4);
    sortArr.push_back(3);

    correctArr.push_back(9);
    correctArr.push_back(8);
    correctArr.push_back(7);
    correctArr.push_back(6);
    correctArr.push_back(5);
    correctArr.push_back(4);
    correctArr.push_back(3);

    std::sort(correctArr.begin(), correctArr.end());
    heapSort(sortArr.begin(), sortArr.end());

    ASSERT_EQ(correctArr, sortArr);
}

TEST(TestShellSort, BasicTest) {
    std::vector<int> sortArr, correctArr;
    sortArr.push_back(9);
    sortArr.push_back(8);
    sortArr.push_back(7);
    sortArr.push_back(6);
    sortArr.push_back(5);
    sortArr.push_back(4);
    sortArr.push_back(3);

    correctArr.push_back(9);
    correctArr.push_back(8);
    correctArr.push_back(7);
    correctArr.push_back(6);
    correctArr.push_back(5);
    correctArr.push_back(4);
    correctArr.push_back(3);

    std::sort(correctArr.begin(), correctArr.end());
    shellSort(sortArr.begin(), sortArr.end());

    ASSERT_EQ(correctArr, sortArr);
}

TEST(TestInsertionSort, RandomizedTest) {
    std::vector<int> sortArr, correctArr;

    int randFrom = 0, randTo = 10001000, randVal = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(randFrom, randTo);

    for (int i = 0; i < 100000; i++) {
        randVal = distribution(generator);

        sortArr.push_back(randVal);
        correctArr.push_back(randVal);
    }

    std::sort(correctArr.begin(), correctArr.end());

    // Time Test.
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(sortArr.begin(), sortArr.end());
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Insertion sort: " << duration.count() << std::endl;
}


TEST(TestShellSort, RandomizedTest) {
    std::vector<int> sortArr, correctArr;

    int randFrom = 0, randTo = 10001000, randVal = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(randFrom, randTo);

    for (int i = 0; i < 100000; i++) {
        randVal = distribution(generator);

        sortArr.push_back(randVal);
        correctArr.push_back(randVal);
    }

    std::sort(correctArr.begin(), correctArr.end());

    // Time Test.
    auto start = std::chrono::high_resolution_clock::now();
    shellSort(sortArr.begin(), sortArr.end());
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Shell sort: " << duration.count() << std::endl;
}


TEST(TestMergSort, RandomizedTest) {
    std::vector<int> sortArr, correctArr;

    int randFrom = 0, randTo = 10001000, randVal = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(randFrom, randTo);

    for (int i = 0; i < 100000; i++) {
        randVal = distribution(generator);

        sortArr.push_back(randVal);
        correctArr.push_back(randVal);
    }

    std::sort(correctArr.begin(), correctArr.end());

    // Time Test.
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(sortArr.begin(), sortArr.end());
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Merge sort: " << duration.count() << std::endl;
}


TEST(TestQuickSort, RandomizedTest) {
    std::vector<int> sortArr, correctArr;

    int randFrom = 0, randTo = 10001000, randVal = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(randFrom, randTo);

    for (int i = 0; i < 100000; i++) {
        randVal = distribution(generator);

        sortArr.push_back(randVal);
        correctArr.push_back(randVal);
    }

    std::sort(correctArr.begin(), correctArr.end());

    // Time Test.
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(sortArr.begin(), sortArr.end());
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Quick sort: " << duration.count() << std::endl;
}


TEST(TestHeapSort, RandomizedTest) {
    std::vector<int> sortArr, correctArr;

    int randFrom = 0, randTo = 10001000, randVal = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(randFrom, randTo);

    for (int i = 0; i < 100000; i++) {
        randVal = distribution(generator);

        sortArr.push_back(randVal);
        correctArr.push_back(randVal);
    }

    std::sort(correctArr.begin(), correctArr.end());

    // Time Test.
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(sortArr.begin(), sortArr.end());
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Heap sort: " << duration.count() << std::endl;
}