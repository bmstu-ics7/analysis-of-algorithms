#include <iostream>
#include <chrono>

#include "DefaultMultiplication.h"
#include "VinogradMultiplication.h"
#include "ModifiedVinogradMultiplication.h"

using namespace std::chrono;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    Matrix matrix1;
    Matrix matrix2;

    switch(argc) {
    case 2:
        if (atoi(argv[1]) < 1) return -2;
        matrix1 = CreateMatrix(atoi(argv[1]), atoi(argv[1]));
        matrix2 = CreateMatrix(atoi(argv[1]), atoi(argv[1]));
        break;
    case 5:
        if (atoi(argv[1]) < 1 ||
            atoi(argv[2]) < 1 ||
            atoi(argv[3]) < 1 ||
            atoi(argv[4]) < 1) return -2;
        matrix1 = CreateMatrix(atoi(argv[1]), atoi(argv[2]));
        matrix2 = CreateMatrix(atoi(argv[3]), atoi(argv[4]));
        break;
    default:
        return -1;
    }

    high_resolution_clock::time_point t1, t2;

    std::cout << "\e[1mПервая матрица\e[0m" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "\e[1mВторая матрица\e[0m" << std::endl;
    std::cout << matrix2 << std::endl;

    t1 = high_resolution_clock::now();
    Matrix result1 = DefaultMultiplication::multiplication(matrix1, matrix2);
    t2 = high_resolution_clock::now();
    
    if (result1.size() == 0) return -2;
    
    std::cout << "\e[1mРезультат стандартного алгоритма\e[0m" << std::endl;
    std::cout << result1;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl << std::endl;

    t1 = high_resolution_clock::now();
    Matrix result2 = VinogradMultiplication::multiplication(matrix1, matrix2);
    t2 = high_resolution_clock::now();
     
    std::cout << "\e[1mРезультат алгоритма Винограда\e[0m" << std::endl;
    std::cout << result2;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl << std::endl;

    t1 = high_resolution_clock::now();
    Matrix result3 = ModifiedVinogradMultiplication::multiplication(matrix1, matrix2);
    t2 = high_resolution_clock::now();
     
    std::cout << "\e[1mРезультат модифицированного алгоритма Винограда\e[0m" << std::endl;
    std::cout << result3;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl << std::endl;

    return 0;
}
