#include <iostream>
#include <gtest/gtest.h>
#include "thread_exercise.h"

int m_size = 1920;
std::vector<std::vector<double>> matrix(m_size, std::vector<double>(m_size));
std::vector<std::vector<double>> base;

namespace {
    TEST(NumerousThreads, LessThanPhCores){
        thread_quantity = 2;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
    TEST(NumerousThreads, EqualToPhCores){
        thread_quantity = 4;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
    TEST(NumerousThreads, EqualToLogCores){
        thread_quantity = 8;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
    TEST(NumerousThreads, ToLogCores2x){
        thread_quantity = 16;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
    TEST(NumerousThreads, ToLogCores4x){
        thread_quantity = 32;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
    TEST(NumerousThreads, ToLogCores8x){
        thread_quantity = 64;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
    TEST(NumerousThreads, ToLogCores16x){
        thread_quantity = 128;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }

    TEST(DiffDimData, LargerData){
        m_size = 8000;
        decltype(matrix) newm (m_size, std::vector<double>(m_size));
        generate_matrix(newm);
        auto newb = newm;
        thread_quantity = 8;
        print_results(newm);
        EXPECT_TRUE(check_identity(newb,newm));
    }

    TEST(DiffDimData, SmallerData){
        matrix.resize(400);
        thread_quantity = 8;
        base.clear();
        base = matrix;
        print_results(matrix);
        EXPECT_TRUE(check_identity(base,matrix));
    }
}
