#include "Matrix.h"

Matrix CreateMatrix(size_t n, size_t m)
{
    Matrix matrix;
    int maxGenerate = n * m / 2;

    for (int i = 0; i < n; ++i) {
        std::vector< int > line;
        for (int j = 0; j < m; ++j) {
            line.push_back(rand() % maxGenerate);
        }
        matrix.push_back(line);
    }
    return matrix;
}

Matrix CreateMatrix(size_t n, size_t m, int element)
{
    Matrix matrix;

    for (int i = 0; i < n; ++i) {
        std::vector< int > line;
        for (int j = 0; j < m; ++j) {
            line.push_back(element);
        }
        matrix.push_back(line);
    }
    return matrix;
}

std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
{
    for (auto line : matrix) {
        for (auto element : line) {
            output << element << '\t';
        }
        output << std::endl;
    }
    return output;
}


Array CreateArray(size_t n)
{
    Array array;
    
    for (int i = 0; i < n; ++i) {
        array.push_back(0);
    }

    return array;
}
