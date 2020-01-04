#ifndef __QSORT_H
#define __QSORT_H

#include <vector>

template < typename Type >
class QSort
{
public:
    static void sort(std::vector< Type >& array, bool (*comp)(Type, Type));
private:
    static void recursive(std::vector< Type >& array, int start, int finish, bool (*comp)(Type, Type));
};

#include "QSort.hpp"

#endif // __QSORT_H
