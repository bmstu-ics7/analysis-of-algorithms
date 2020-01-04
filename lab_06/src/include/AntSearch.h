#ifndef __ANTSEARCH_H
#define __ANTSEARCH_H

#include "Matrix.h"

class AntSearch
{
public:
    static std::pair< std::vector< size_t >, size_t> way(const Matrix< size_t >& distances, double alpha, double beta, double rho, double tmax);
};

#endif // __ANTSEARCH_H
