#ifndef __SHAKERSORT_H
#define __SHAKERSORT_H

#include <vector>

template < typename Type >
class ShakerSort
{
public:
    static void sort(std::vector< Type >& array, bool (*comp)(Type, Type));
};

#include "ShakerSort.hpp"

#endif // __SHAKERSORT_H
