#ifndef __SHAKERSORT_HPP
#define __SHAKERSORT_HPP

#include "ShakerSort.h"

template < typename Type >
void ShakerSort< Type >::sort(std::vector< Type >& array, bool (*comp)(Type, Type))
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        for (int i = left; i < right; ++i) {
            if (comp(array[i], array[i + 1])) {
                std::swap(array[i], array[i + 1]);
            }
        }
        --right;

        for (int i = right; i > left; --i) {
            if (comp(array[i - 1], array[i])) {
                std::swap(array[i - 1], array[i]);
            }
        }
        ++left;
    }
}

#endif // __SHAKERSORT_HPP
