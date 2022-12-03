cmake_minimum_required(VERSION 3.23)
project(MyDSLearning)

set(CMAKE_CXX_STANDARD 17)

include_directories(List)

add_subdirectory(Google_tests)

#set(BST Tree/BinarySearchTree/BSTTest.cpp)
#set(AvlTree Tree/AvlTree/AvlTreeTest.cpp)
#set(LIST List/List/List.cpp List/List/List.inl)
#set(VECTOR List/Vector/Vector.cpp)
#set(HASH HashTable/QuadraticProbingTest.cpp)
#set(SPELLCHECKER HashTable/SpellChecker.cpp HashTable/SpellCheckerTest.cpp)
#set(SORTING Sort/TestSorting.cpp)
#set(QuickUnion Union/QuickUnion.cpp)

add_executable(MyDSLearning main.cpp
        ${LIST}
        ${VECTOR}
        ${BST}
        ${AvlTree}
        ${UTree}
        ${HASH}
        ${SPELLCHECKER}
        ${SORTING}
        ${QuickUnion})
