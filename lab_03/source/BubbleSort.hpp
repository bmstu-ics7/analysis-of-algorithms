#ifndef __BUBBLESORT_HPP
#define __BUBBLESORT_HPP

#include "BubbleSort.h"

template < typename Type >
void BubbleSort< Type >::sort(std::vector< Type >& array, bool (*comp)(Type, Type))
{
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < array.size() - i - 1; ++j) {
            if (comp(array[j], array[j + 1])) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

#endif // __BUBBLESORT_HPP
