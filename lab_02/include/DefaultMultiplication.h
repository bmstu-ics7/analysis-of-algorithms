#ifndef __DEFAULTMULTIPLICATION_H
#define __DEFAULTMULTIPLICATION_H

#include "Matrix.h"

class DefaultMultiplication
{
public:
    static Matrix multiplication(const Matrix& first, const Matrix& second);
};

#endif // __DEFAULTMULTIPLICATION_H
