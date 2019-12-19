#ifndef __FULLSEARH_H
#define __FULLSEARH_H

#include "Matrix.h"

class FullSearch
{
public:
    static std::pair< std::vector< size_t >, size_t> way(const Matrix< size_t >& distances);

private:
    static void recursive(const Matrix< size_t >& distances, std::vector< size_t >& indexes, size_t curIndex);
    static size_t distance(const Matrix< size_t >& distances, const std::vector< size_t >& indexes);

    static std::vector< size_t > minWay;
    static size_t minDist;
};

#endif // __FULLSEARH_H
