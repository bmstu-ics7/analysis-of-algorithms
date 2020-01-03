#include <CoutVector.h>

std::ostream& operator<<(std::ostream& out, const std::vector< std::vector< int > >& matrix)
{
    for (auto line : matrix) {
        for (auto el : line) {
            out << el << '\t';
        }
        out << std::endl;
    }
    return out;
}
