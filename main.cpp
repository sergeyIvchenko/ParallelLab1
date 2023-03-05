#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <windows.h>
#include <random>
#include <thread>
#include <iterator>

using namespace std::chrono;

auto count_time(std::function<void(std::vector<std::vector<double>>&)> func, auto& matrix){
    auto start = high_resolution_clock::now();
    func(matrix);
    auto end = high_resolution_clock::now();
    return duration<double>(end-start).count();
}

void transpose(std::vector<std::vector<double>>& matrix){
    for(int i=0; i<matrix.size();++i){
        for(int j=i+1; j<matrix.size();++j){
            std::swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Уведіть розмірність матриці NxN:";
    int m_size;
    std::cin >> m_size;
    std::vector<std::vector<double>> matrix(m_size,std::vector<double>(m_size));
    std::random_device rd;
    std::uniform_real_distribution<double> gen(1,100);
    for(auto& row:matrix) {
        std::generate(row.begin(), row.end(),[&gen,&rd]{return gen(rd);});
    }
    std::cout.precision(10);
    std::cout << count_time(transpose, matrix) << std::endl;
    return 0;
}
