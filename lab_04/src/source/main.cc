#include <iostream>
#include <chrono>
#include <thread>
#include "ThreadMultiplication.h"

using namespace std::chrono;

int main(int argc, char* argv[])
{
    if (argc != 3) return -1;
    int n = atoi(argv[1]);
    int threads = atoi(argv[2]);

    if (n < 1 || threads < 1 || n < threads) return -2;

    std::cout << "\e[1mCount of threads: \e[0m" << threads << std::endl << std::endl;

    Matrix mat1 = CreateMatrix(n, n);
    Matrix mat2 = CreateMatrix(n, n);
    Matrix result = CreateMatrix(n, n, 0);

    int start = 0;
    int finish = n / threads - 1 + n % threads;
    std::vector< std::thread > all;

    for (int i = 0; i < threads; ++i) {
        all.push_back(std::thread(ThreadMultiplication::multiplication, 
                                  std::ref(mat1), std::ref(mat2), std::ref(result), start, finish));

        start = finish + 1;
        finish += n / threads;
    }

    high_resolution_clock::time_point t1, t2;

    t1 = high_resolution_clock::now();
    for (auto& th : all) {
        th.join();
    }
    t2 = high_resolution_clock::now();

    std::cout << "\e[1mПервая матрица:\e[0m" << std::endl;
    std::cout << mat1 << std::endl;

    std::cout << "\e[1mВторая матрица:\e[0m" << std::endl;
    std::cout << mat2 << std::endl;

    std::cout << "\e[1mРезультат:\e[0m" << std::endl;
    std::cout << result << std::endl;

    std::cout << "\e[1mTime: \e[0m";
    std::cout << duration_cast<microseconds>(t2 - t1).count() << std::endl;

    return 0;
}
