#ifndef __BUBBLESORT_H
#define __BUBBLESORT_H

#include <vector>

template < typename Type >
class BubbleSort
{
public:
    static void sort(std::vector< Type >& array, bool (*comp)(Type, Type));
};

#include "BubbleSort.hpp"

#endif // __BUBBLESORT_H
