#include "tests.cc"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    testing::InitGoogleTest();
//    std::cout << "Уведіть розмірність матриці NxN:";
//    int m_size;
//    std::cin >> m_size;
//    std::cout << "Уведіть кількість потоків:";
//    std::cin >> thread_quantity;
//    std::vector<std::vector<double>> matrix(m_size, std::vector<double>(m_size));
//
//    std::random_device rd;
//    std::uniform_real_distribution<double> gen(1, 100);
//    for (auto &row: matrix) {
//        std::generate(row.begin(), row.end(), [&gen, &rd] { return gen(rd); });
//    }
//    auto tmp = matrix;
//    std::cout.precision(10);
//    std::cout << count_time(one_thread_transpose, matrix) << std::endl;
//    std::cout << count_time(many_thread_transpose, matrix) << std::endl;
//    std::cout.precision(6);
//    std::cout << check_identity(tmp,matrix);
    return RUN_ALL_TESTS();
}
