cmake_minimum_required(VERSION 3.9)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenMP REQUIRED)
add_subdirectory(D:/googletest-main/googletest googletest)
include_directories(googletest/googletest/include)
add_executable(lab1 main.cpp thread_exercise.h)
if(OpenMP_CXX_FOUND)
    message("OpenMp found")
    target_link_libraries(lab1 gtest OpenMP::OpenMP_CXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
else()
    message("Not found")
    target_link_libraries(lab1 gtest)
endif()

