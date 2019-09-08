#include "Lmatrix.h"

int Lmatrix::find(std::string s1, std::string s2)
{
    std::vector< std::vector< int > > matrix;
    for (int i = 0; i < s1.size() + 1; ++i) {
        matrix.push_back(std::vector< int >(s2.size() + 1));
    }

    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][0] = i;
    }

    for (int j = 0; j < matrix[0].size(); ++j) {
        matrix[0][j] = j;
    }

    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            int u = matrix[i - 1][j] + 1;
            int l = matrix[i][j - 1] + 1;
            int lu = matrix[i - 1][j - 1];
            if (s1[i - 1] != s2[j - 1]) lu++;

            matrix[i][j] = std::min(std::min(u, l), lu);
        }
    }

    for (auto line : matrix) {
        for (int el : line) {
            std::cout << el << '\t';
        }
        std::cout << std::endl;
    }

    return matrix[matrix.size() - 1][matrix[0].size() - 1];
}
