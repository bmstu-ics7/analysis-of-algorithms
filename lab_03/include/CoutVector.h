#ifndef __COUTVECTOR_H
#define __COUTVECTOR_H

#include <iostream>
#include <vector>

template < typename Type >
std::ostream& operator<<(std::ostream& out, const std::vector< Type >& array);

#include "CoutVector.hpp"

#endif // __COUTVECTOR_H
