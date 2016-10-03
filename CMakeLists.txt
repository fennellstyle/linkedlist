cmake_minimum_required(VERSION 3.6)
project(linkedlist)

enable_testing()
find_package (Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES linkedlist.h test.cpp)
add_executable(linkedlist ${SOURCE_FILES})
target_link_libraries(linkedlist ${GTEST_BOTH_LIBRARIES})
target_link_libraries (linkedlist ${CMAKE_THREAD_LIBS_INIT})
add_test(LinkedListTest linklist)
