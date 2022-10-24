cmake_minimum_required(VERSION 3.23)
project(MyDSLearning)

set(CMAKE_CXX_STANDARD 17)

include_directories(ListAndVector)

set(BST Tree/BinarySearchTree/BSTTest.cpp)
#set(LIST ListAndVector/List/List.cpp ListAndVector/List/List.inl)
#set(VECTOR ListAndVector/Vector/Vector.cpp)

add_executable(MyDSLearning
        ${LIST}
        ${VECTOR}
        ${BST})
