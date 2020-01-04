#ifndef __MATRIX_HPP
#define __MATRIX_HPP

#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(size_t size)
    : Matrix<T>(size, 0) { }

template <typename T>
Matrix<T>::Matrix(size_t size, T el)
{
    for (int i = 0; i < size; ++i) {
        data.push_back(std::vector< T >(size, el));
    }
}

template <typename T>
Matrix<T>::Matrix(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) return;

    size_t n;
    file >> n;

    for (int i = 0; i < n; ++i) {
        data.push_back(std::vector< T >(n));
        for (int j = 0; j < n; ++j) {
            file >> data[i][j];
        }
    }

    file.close();
}

template <typename T>
std::vector< T >& Matrix<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
const std::vector< T >& Matrix<T>::operator[](size_t index) const
{
    return data[index];
}

template <typename T>
size_t Matrix<T>::size()
{
    return data.size();
}

template <typename T>
size_t Matrix<T>::size() const
{
    return data.size();
}

template <typename T>
std::ostream& operator<< (std::ostream& output, const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            output << matrix[i][j] << '\t';
        }
        output << std::endl;
    }

    return output;
}

#endif // __MATRIX_HPP
