#include <iostream>
#include <fstream>
#include <vector>

typedef std::vector< std::vector< int > > Matrix;
typedef std::vector< int > Array;

class Multiplication
{
public:
    Array mulU;
    Array mulV;

    Multiplication() { }
    ~Multiplication() { }

    // Pipeline 1
    void inputMatrix1(std::ifstream& input);
    void inputMatrix2(std::ifstream& input);
    void createResult();

    // Pipeline 2
    void calcMulU();
    void calcMulV();

    // Pipeline 3
    void calculate1();

    // Pipeline 4
    void calculate2();
    void check();

    // Pipeline 5
    Matrix get();

private:
    Matrix first;
    int n1;
    int m1;

    Matrix second;
    int n2;
    int m2;

    Matrix result;
};
