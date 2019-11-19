#include "Conveyor.h"

std::ifstream Conveyor::input = std::ifstream();
queue Conveyor::queuePipeline2 = queue();
queue Conveyor::queuePipeline3 = queue();
queue Conveyor::queuePipeline4 = queue();
queue Conveyor::queueResult = queue();
bool Conveyor::stopPipline1 = false;
bool Conveyor::stopPipline2 = false;
bool Conveyor::stopPipline3 = false;

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
    while (true)
    {
        std::string buf;
        input >> buf;
        std::cout << "pip1" << std::endl;

        if (input.eof()) {
            stopPipline1 = true;
            return;
        }

        Multiplication mult;
        mult.inputMatrix1(input);
        mult.inputMatrix2(input);
        mult.createResult();

        queuePipeline2.push(mult);
    }
}

void Conveyor::functionPipeline2()
{
    while (true)
    {
        if (stopPipline1 &&
            queuePipeline2.empty()) {
            stopPipline2 = true;
            return;
        }

        if (queuePipeline2.empty()) continue;
        std::cout << "pip2" << std::endl;

        Multiplication mult = queuePipeline2.front();
        queuePipeline2.pop();

        mult.calcMulU();
        mult.calcMulV();

        queuePipeline3.push(mult);
    }
}

void Conveyor::functionPipeline3()
{
    while (true)
    {
        if (stopPipline2 &&
            queuePipeline3.empty()) {
            stopPipline3 = true;
            return;
        }

        if (queuePipeline3.empty()) continue;
        std::cout << "pip3" << std::endl;

        Multiplication mult = queuePipeline3.front();
        queuePipeline3.pop();

        mult.calculate1();

        queuePipeline4.push(mult);
    }
}

void Conveyor::functionPipeline4()
{
    while (true)
    {
        if (stopPipline3 &&
            queuePipeline4.empty()) {
            return;
        }

        if (queuePipeline4.empty()) continue;
        std::cout << "pip4" << std::endl;

        Multiplication mult = queuePipeline4.front();
        queuePipeline4.pop();

        mult.calculate2();
        mult.check();

        queueResult.push(mult);
    }
}
