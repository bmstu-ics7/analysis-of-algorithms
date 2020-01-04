#include "FullSearch.h"
#include "AntSearch.h"

#define BOLD_ON  "\e[1m"
#define BOLD_OFF "\e[0m"

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    Matrix< size_t > matrix(argv[1]);

    if (matrix.size() == 0) return -2;

    auto result = FullSearch::way(matrix);

    std::cout << BOLD_ON << "Алгоритм перебора:" << BOLD_OFF << std::endl;
    for (int i = 0; i < result.first.size(); ++i)
        std::cout << result.first[i] << ' ';
    std::cout << std::endl;

    std::cout << "dist = " << result.second << std::endl << std::endl;

    // alpha, beta, rho, tmax
    result = AntSearch::way(matrix, 0.4, 0.6, 0.5, 1200);

    std::cout << BOLD_ON << "Муравьиный алгоритм:" << BOLD_OFF << std::endl;
    for (int i = 0; i < result.first.size(); ++i)
        std::cout << result.first[i] << ' ';
    std::cout << std::endl;

    std::cout << "dist = " << result.second << std::endl;

    return 0;
}
