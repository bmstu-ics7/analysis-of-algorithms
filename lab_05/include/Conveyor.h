#include <queue>
#include <chrono>
#include <thread>
#include "Multiplication.h"

using namespace std::chrono;

typedef std::queue< Multiplication > queue;

class Conveyor
{
public:
    static bool open(std::string filename);
    static void close();
    static void printall();

    static void functionPipeline1();
    static void functionPipeline2();
    static void functionPipeline3();
    static void functionPipeline4();

private:
    static std::ifstream input;

    static queue queuePipeline2;
    static queue queuePipeline3;
    static queue queuePipeline4;

    static bool stopPipeline1;
    static bool stopPipeline2;
    static bool stopPipeline3;

    static std::queue< Multiplication > queueResult;

public:
    static unsigned int timePipeline1;
    static unsigned int timePipeline2;
    static unsigned int timePipeline3;
    static unsigned int timePipeline4;
};
