#ifndef __QSORT_HPP
#define __QSORT_HPP

#include "QSort.h"
#include <iostream>

template < typename Type >
void QSort< Type >::sort(std::vector< Type >& array, bool (*comp)(Type, Type))
{
    recursive(array, 0, array.size() - 1, comp);
}

template < typename Type >
void QSort< Type >::recursive(std::vector< Type >& array, int start, int finish, bool (*comp)(Type, Type))
{
    if (start < finish) {
        int left = start, right = finish;
        Type middle = array[(left + right) >> 1];

         while (left <= right) {
            while (comp(middle, array[left])) left++;
            while (comp(array[right], middle)) right--;

            if (left <= right) {
                std::swap(array[left], array[right]);
                ++left;
                --right;
            }
        }

        if (start < right) recursive(array, start, right, comp);
        if (left < finish) recursive(array, left, finish, comp);
    }
}

#endif // __QSORT_HPP
