#include <iostream>
#include <thread>
#include <chrono>
#include "Conveyor.h"

using namespace std::chrono;

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    if (!Conveyor::open(argv[1])) return -2;

    std::thread t1 = std::thread(Conveyor::functionPipeline1);
    std::thread t2 = std::thread(Conveyor::functionPipeline2);
    std::thread t3 = std::thread(Conveyor::functionPipeline3);
    std::thread t4 = std::thread(Conveyor::functionPipeline4);

    high_resolution_clock::time_point time1, time2;
    time1 = high_resolution_clock::now();

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    time2 = high_resolution_clock::now();
    std::cout << "\e[1mConveer: \e[0m";
    std::cout << duration_cast<microseconds>(time2 - time1).count() << std::endl;

    std::cout << "\e[1mPipeline1: \e[0m" << Conveyor::timePipeline1 << std::endl;
    std::cout << "\e[1mPipeline2: \e[0m" << Conveyor::timePipeline2 << std::endl;
    std::cout << "\e[1mPipeline3: \e[0m" << Conveyor::timePipeline3 << std::endl;
    std::cout << "\e[1mPipeline4: \e[0m" << Conveyor::timePipeline4 << std::endl;

    Conveyor::close();

    std::ifstream file;
    file.open(argv[1]);

    time1 = high_resolution_clock::now();

    while (true) {
        std::string buf;
        file >> buf;

        if (file.eof()) {
            break;
        }

        Multiplication mult;
        mult.inputMatrix1(file);
        mult.inputMatrix2(file);
        mult.createResult();
        mult.calcMulU();
        mult.calcMulV();
        mult.calculate1();
        mult.calculate2();
        mult.check();
    }

    time2 = high_resolution_clock::now();
    std::cout << "\e[1mOne thread: \e[0m";
    std::cout << duration_cast<microseconds>(time2 - time1).count() << std::endl;

    file.close();

    return 0;
}
