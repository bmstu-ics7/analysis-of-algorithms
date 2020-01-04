#include "ModifiedVinogradMultiplication.h"

Matrix ModifiedVinogradMultiplication::multiplication(const Matrix& first, const Matrix& second)
{
    Matrix result;
    if (first[0].size() != second.size()) return result;
    result = CreateMatrix(first.size(), second[0].size(), 0);

    const int m = first.size();
    const int n = second.size();
    const int q = second[0].size();

    Array mulU = CreateArray(m);
    Array mulV = CreateArray(q);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n - 1; j += 2)
            mulU[i] -=
                first[i][j] * first[i][j + 1];

    for (int j = 0; j < q; ++j)
        for (int i = 0; i < n - 1; i += 2)
            mulV[j] -=
                second[i][j] * second[i + 1][j];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            result[i][j] = mulU[i] + mulV[j];
            for (int k = 0; k < n - 1; k += 2) {
                result[i][j] +=
                    (first[i][k] + second[k + 1][j]) *
                    (first[i][k + 1] + second[k][j]);
            }
        }
    }

    if (n % 2 == 1)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < q; ++j)
                result[i][j] +=
                    first[i][n - 1] * second[n - 1][j];

    return result;
}
