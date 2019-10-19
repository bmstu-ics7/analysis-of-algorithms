#include "DLmatrix.h"

Matrix DLmatrix::find(std::string s1, std::string s2)
{
    Matrix matrix;
    for (int i = 0; i < s1.size() + 1; ++i) {
        matrix.push_back(std::vector< int >(s2.size() + 1));
    }

    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][0] = i;
    }

    for (int j = 0; j < matrix[0].size(); ++j) {
        matrix[0][j] = j;
    }

    int inf = std::max(s1.size(), s2.size()) + 1;

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            int u = matrix[i - 1][j] + 1;
            int l = matrix[i][j - 1] + 1;
            int lu = matrix[i - 1][j - 1];
            int lluu = inf;
            if (i > 1 && j > 1) lluu = matrix[i - 2][j - 2];

            if (s1[i - 1] != s2[j - 1]) lu++;
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) lluu++;
            else lluu = inf;

            matrix[i][j] = std::min(std::min(u, l), std::min(lu, lluu));
        }
    }

    return matrix;
}
