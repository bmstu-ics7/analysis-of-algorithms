#ifndef __MATRIX_H
#define __MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class Matrix
{
public:
    Matrix(size_t size);
    Matrix(size_t size, T el);
    Matrix(const std::string& filename);

    size_t size();
    size_t size() const;

    std::vector< T >& operator[](size_t index);
    const std::vector< T >& operator[](size_t index) const;

private:
    std::vector< std::vector< T > > data;
};

template <typename T>
std::ostream& operator<< (std::ostream& output, const Matrix<T>& matrix);

#include "Matrix.hpp"

#endif // __MATRIX_H
