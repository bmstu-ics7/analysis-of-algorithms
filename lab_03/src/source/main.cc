#include <iostream>
#include <vector>
#include <chrono>

#include "BubbleSort.h"
#include "ShakerSort.h"
#include "QSort.h"
#include "CoutVector.h"

using namespace std::chrono;

bool comp(int a, int b) { return a > b; }

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;
    int count = std::atoi(argv[1]);

    srand(time(NULL));

    std::vector< int > arr1;
    for (int i = 0; i < count; ++i) arr1.push_back(rand() % count);
    std::vector< int > arr2 = arr1;
    std::vector< int > arr3 = arr1;

    high_resolution_clock::time_point t1, t2;

    std::cout << "\e[1mИсходный массив:\e[0m" << std::endl;
    std::cout << arr1 << std::endl << std::endl;

    std::cout << "\e[1mСортировка пузырьком:\e[0m" << std::endl;
    t1 = high_resolution_clock::now();
    BubbleSort< int >::sort(arr1, comp);
    t2 = high_resolution_clock::now();
    std::cout << arr1 << std::endl;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl << std::endl;

    std::cout << "\e[1mСортировка шейкером:\e[0m" << std::endl;
    t1 = high_resolution_clock::now();
    ShakerSort< int >::sort(arr2, comp);
    t2 = high_resolution_clock::now();
    std::cout << arr2 << std::endl;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl << std::endl;

    std::cout << "\e[1mБыстрая сортировка:\e[0m" << std::endl;
    t1 = high_resolution_clock::now();
    QSort< int >::sort(arr3, comp);
    t2 = high_resolution_clock::now();
    std::cout << arr3 << std::endl;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl << std::endl;

    return 0;
}
