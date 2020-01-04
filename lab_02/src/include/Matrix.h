#ifndef __MATRIX_H
#define __MATRIX_H

#include <vector>
#include <iostream>

typedef std::vector< std::vector< int > > Matrix;

Matrix CreateMatrix(size_t n, size_t m);
Matrix CreateMatrix(size_t n, size_t m, int element);
std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

typedef std::vector< int > Array;

Array CreateArray(size_t n);

#endif // __MATRIX_H
