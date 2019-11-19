#include <iostream>
#include <thread>
#include "Conveyor.h"

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    if (!Conveyor::open(argv[1])) return -2;

    std::thread t1 = std::thread(Conveyor::functionPipeline1);
    std::thread t2 = std::thread(Conveyor::functionPipeline2);
    std::thread t3 = std::thread(Conveyor::functionPipeline3);
    std::thread t4 = std::thread(Conveyor::functionPipeline4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    Conveyor::close();
    //Conveyor::printall();

    return 0;
}
