#include "Multiplication.h"

// Pipeline 1
void Multiplication::inputMatrix1(std::ifstream& input)
{
    input >> n1 >> m1;

    for (int i = 0; i < n1; ++i) {
        Array line;

        for (int j = 0; j < m1; ++j) {
            int element;
            input >> element;
            line.push_back(element);
        }

        first.push_back(line);
    }
}

void Multiplication::inputMatrix2(std::ifstream& input)
{
    input >> n2 >> m2;

    for (int i = 0; i < n2; ++i) {
        Array line;

        for (int j = 0; j < m2; ++j) {
            int element;
            input >> element;
            line.push_back(element);
        }

        second.push_back(line);
    }
}

void Multiplication::createResult()
{
    if (m1 != n2) return;

    for (int i = 0; i < n1; ++i) {
        Array line;

        for (int j = 0; j < m2; ++j) {
            line.push_back(0);
        }

        result.push_back(line);
    }

    for (int i = 0; i < n1; ++i) {
        mulU.push_back(0);
    }

    for (int i = 0; i < m2; ++i) {
        mulV.push_back(0);
    }

}

// Pipeline 2
void Multiplication::calcMulU()
{
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n2 - 1; j += 2)
            mulU[i] -=
                first[i][j] * first[i][j + 1];
}

void Multiplication::calcMulV()
{
    for (int j = 0; j < m2; ++j)
        for (int i = 0; i < n2 - 1; i += 2)
            mulV[j] -=
                second[i][j] * second[i + 1][j];
}

// Pipeline 3
void Multiplication::calculate1()
{
    for (int i = 0; i < (n1 >> 1) + 1; ++i) {
        for (int j = 0; j < m2; ++j) {
            result[i][j] = mulU[i] + mulV[j];
            for (int k = 0; k < n2 - 1; k += 2) {
                result[i][j] +=
                    (first[i][k] + second[k + 1][j]) *
                    (first[i][k + 1] + second[k][j]);
            }
        }
    }
}

// Pipeline 4
void Multiplication::calculate2()
{
    for (int i = (n1 >> 1) + 1; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            result[i][j] = mulU[i] + mulV[j];
            for (int k = 0; k < n2 - 1; k += 2) {
                result[i][j] +=
                    (first[i][k] + second[k + 1][j]) *
                    (first[i][k + 1] + second[k][j]);
            }
        }
    }
}

void Multiplication::check()
{
    if (n2 % 2 == 1)
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < m2; ++j)
                result[i][j] +=
                    first[i][n2 - 1] * second[n2 - 1][j];
}

// Pipeline 5
Matrix Multiplication::get()
{
    return result;
}
