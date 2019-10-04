#ifndef __COUTVECTOR_HPP
#define __COUTVECTOR_HPP

#include "CoutVector.h"

template < typename Type >
std::ostream& operator<<(std::ostream& out, const std::vector< Type >& array)
{
    for (int i = 0; i < array.size(); ++i) {
        out << array[i] << ' ';
    }
    return out;
}

#endif // __COUTVECTOR_HPP
