cmake_minimum_required(VERSION 4.0)
project(Algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithms main.cpp)

add_executable(sort_test sort_algorithms/sort_test.cpp)
add_executable(maximum_subarray_test Chapter4/maximum_subarray_test.cpp)
add_executable(strassen_test Chapter4/strassen_test.cpp)
add_executable(maxheap_test data_structure/maxheap_test.cpp)