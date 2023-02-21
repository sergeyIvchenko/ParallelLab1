#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <windows.h>

using namespace std::chrono;

double count_time(auto& func){
    double work_time;

    return work_time;
}

void transpose(std::vector<std::vector<double>>& matrix){


}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Уведіть розмірність матриці NxN:";
    int m_size;
    std::cin >> m_size;
    std::vector<std::vector<double>> matrix(m_size,std::vector<double>(m_size));
    return 0;
}
