#include "DefaultMultiplication.h"

Matrix DefaultMultiplication::multiplication(const Matrix& first, const Matrix& second)
{
    Matrix result;
    if (first[0].size() != second.size()) return result;
    result = CreateMatrix(first.size(), second[0].size(), 0);

    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < second[0].size(); ++j) {
            for (int k = 0; k < second.size(); ++k) {
                result[i][j] = result[i][j] + first[i][k] * second[k][j];
            }
        }
    }

    return result;
}
