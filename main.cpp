#include "tests.cc"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    testing::InitGoogleTest();
    generate_matrix(matrix);
    base = matrix;

    return RUN_ALL_TESTS();
}
