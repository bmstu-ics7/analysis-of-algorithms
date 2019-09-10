#include <iostream>
#include <chrono>

#include "Lmatrix.h"
#include "DLmatrix.h"
#include "DLrecursive.h"
#include "CoutVector.h"

using namespace std::chrono;

int main(int argc, char* argv[])
{
    if (argc != 3) return -1;

    std::string s1 = argv[1], s2 = argv[2];
    std::cout << s1 << " -> " << s2 << std::endl;
    std::cout << s1.size() << ' ' << s2.size() << std::endl;

    high_resolution_clock::time_point t1, t2;

    t1 = high_resolution_clock::now();
    auto res1 = Lmatrix::find(s1, s2);
    t2 = high_resolution_clock::now();
    std::cout << res1;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl;// << std::endl;

    t1 = high_resolution_clock::now();
    auto res2 = DLmatrix::find(s1, s2);
    t2 = high_resolution_clock::now();
    std::cout << res2;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl;// << std::endl;

    t1 = high_resolution_clock::now();
    auto res3 = DLrecursive::find(s1, s2);
    t2 = high_resolution_clock::now();
    std::cout << res3 << std::endl;
    std::cout << "time: " << duration_cast<microseconds>(t2 - t1).count() << std::endl;// << std::endl;

    return 0;
}
