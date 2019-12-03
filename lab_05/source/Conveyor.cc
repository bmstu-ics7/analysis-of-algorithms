#include "Conveyor.h"

std::ifstream Conveyor::input = std::ifstream();
queue Conveyor::queuePipeline2 = queue();
queue Conveyor::queuePipeline3 = queue();
queue Conveyor::queuePipeline4 = queue();
queue Conveyor::queueResult = queue();
bool Conveyor::stopPipeline1 = false;
bool Conveyor::stopPipeline2 = false;
bool Conveyor::stopPipeline3 = false;

unsigned int Conveyor::timePipeline1 = 0;
unsigned int Conveyor::timePipeline2 = 0;
unsigned int Conveyor::timePipeline3 = 0;
unsigned int Conveyor::timePipeline4 = 0;

bool Conveyor::open(std::string filename)
{
    input.open(filename);
    return input.is_open();
}

void Conveyor::close()
{
    input.close();
}

void Conveyor::printall()
{
    while (!queueResult.empty()) {
        Multiplication mult = queueResult.front();
        queueResult.pop();
        for (auto line : mult.get()) {
            for (auto el : line) {
                std::cout << el << '\t';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Conveyor::functionPipeline1()
{
    high_resolution_clock::time_point time1, time2;

    while (true)
    {
        std::string buf;
        input >> buf;

        if (input.eof()) {
            stopPipeline1 = true;
            break;
        }

        time1 = high_resolution_clock::now();

        Multiplication mult;
        mult.inputMatrix1(input);
        mult.inputMatrix2(input);

        queuePipeline2.push(mult);

        time2 = high_resolution_clock::now();
        timePipeline1 += duration_cast<microseconds>(time2 - time1).count();
    }

}

void Conveyor::functionPipeline2()
{
    high_resolution_clock::time_point time1, time2;

    while (true)
    {
        if (stopPipeline1 &&
            queuePipeline2.empty()) {
            stopPipeline2 = true;
            break;
        }

        if (queuePipeline2.empty()) continue;

        time1 = high_resolution_clock::now();

        Multiplication mult = queuePipeline2.front();
        queuePipeline2.pop();

        mult.createResult();
        mult.calcMulU();
        mult.calcMulV();

        queuePipeline3.push(mult);

        time2 = high_resolution_clock::now();
        timePipeline2 += duration_cast<microseconds>(time2 - time1).count();
    }
}

void Conveyor::functionPipeline3()
{
    high_resolution_clock::time_point time1, time2;

    while (true)
    {
        if (stopPipeline2 &&
            queuePipeline3.empty()) {
            stopPipeline3 = true;
            break;
        }

        if (queuePipeline3.empty()) continue;

        time1 = high_resolution_clock::now();

        Multiplication mult = queuePipeline3.front();
        queuePipeline3.pop();

        mult.calculate1();

        queuePipeline4.push(mult);

        time2 = high_resolution_clock::now();
        timePipeline3 += duration_cast<microseconds>(time2 - time1).count();
    }
}

void Conveyor::functionPipeline4()
{
    high_resolution_clock::time_point time1, time2;

    while (true)
    {
        if (stopPipeline3 &&
            queuePipeline4.empty()) {
            break;
        }

        if (queuePipeline4.empty()) continue;

        time1 = high_resolution_clock::now();

        Multiplication mult = queuePipeline4.front();
        queuePipeline4.pop();

        mult.calculate2();
        mult.check();

        queueResult.push(mult);

        time2 = high_resolution_clock::now();
        timePipeline4 += duration_cast<microseconds>(time2 - time1).count();
    }
}
