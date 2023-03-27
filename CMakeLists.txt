cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(D:/googletest-main/googletest googletest)
include_directories(googletest/googletest/include)
add_executable(lab1 main.cpp thread_exercise.h)
target_link_libraries(lab1 gtest -static gcc stdc++ winpthread)
