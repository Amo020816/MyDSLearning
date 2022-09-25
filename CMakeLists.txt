cmake_minimum_required(VERSION 3.23)
project(MyDSLearning)

set(CMAKE_CXX_STANDARD 17)

include_directories(ListAndVector)

set(LIST ListAndVector/ArrayList/ArrayList.cpp)
set(VECTOR ListAndVector/Vector/Vector.cpp)

add_executable(MyDSLearning main.cpp
        ${LIST}
        ${VECTOR})
