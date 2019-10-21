#ifndef __MODIFIEDVINOGRADMULTIPLICATION_H
#define __MODIFIEDVINOGRADMULTIPLICATION_H

#include "Matrix.h"

class ThreadMultiplication
{
public:
    static void multiplication(const Matrix& matrix1,
                               const Matrix& matrix2,
                               Matrix& result,
                               const int start,
                               const int finish);
};

#endif // __MODIFIEDVINOGRADMULTIPLICATION_H
