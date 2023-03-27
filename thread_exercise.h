#ifndef LAB1_THREAD_EXERCISE_H
#define LAB1_THREAD_EXERCISE_H
#include <chrono>
#include <functional>
#include <vector>
#include <windows.h>
#include <random>
#include <thread>
#include <iostream>

using namespace std::chrono;

//Функція знаходження часу роботи функції
//для багатопотокової функції використано .join, а тому виконання функції обмежується областю func()
auto count_time(std::function<void(std::vector<std::vector<double>>&)> func, auto& matrix){
    auto start = high_resolution_clock::now();
    func(matrix);
    auto end = high_resolution_clock::now();
    return duration<double>(end-start).count();
}

void generate_matrix(auto& matrix){
    std::random_device rd;
    std::uniform_real_distribution<double> gen(1, 100);
    for (auto& row: matrix) {
        std::generate(row.begin(), row.end(), [&gen, &rd] { return gen(rd); });
    }
}
int thread_quantity;
//Додаткова функція для many_thread_transpose - саме вона буде додаватись в об'єкти thread
void row_transpose(std::vector<std::vector<double>>& matrix,int index){
    for(int i=index; i<matrix.size()/thread_quantity+index;++i){
        for(int j=i+1;j<matrix.size();++j){
            std::swap(matrix[i][j],matrix[j][i]);
        }
    }
}

void one_thread_transpose(std::vector<std::vector<double>>& matrix){
    std::cout << matrix.size() << std::endl;
    for(int i=0; i<matrix.size();++i){
        for(int j=i+1;j<matrix.size();++j){
            std::swap(matrix[i][j],matrix[j][i]);
        }
    }
}

void many_thread_transpose(std::vector<std::vector<double>>& matrix){
    std::thread threads[thread_quantity];
    //Для того, щод у локальну пам'ять об'єкту передавалось саме посилання, використовується ref()
    for(int j=0,i=0;i<matrix.size();i+=matrix.size()/thread_quantity){
        threads[j] = std::thread(row_transpose, std::ref(matrix),i);
        j++;
    }
    //Вирішив відокремити приєднання від ініціалізації
    for(int i=0;i<thread_quantity;++i){
        threads[i].join();
    }
}

void print_results(auto& matrix){
    std::cout.precision(10);
    std::cout << count_time(one_thread_transpose, matrix) << std::endl;
    std::cout << count_time(many_thread_transpose, matrix) << std::endl;
}
bool check_identity(std::vector<std::vector<double>>& basematrix, auto& transposedmatrix){
    for (int i = 0; i < basematrix.size(); ++i) {//Умова правильного виконання функцій(буде використана для тестування)
        for (int j = 0; j < basematrix.size(); ++j) {
            if (transposedmatrix[i][j] != basematrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}
#endif //LAB1_THREAD_EXERCISE_H
