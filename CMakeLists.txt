cmake_minimum_required(VERSION 3.29)
project(HW2_circular_doubly_linked_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW2_circular_doubly_linked_list
        DLinkedList.h
    main.cpp)
