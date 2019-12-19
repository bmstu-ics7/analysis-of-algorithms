#include "FullSearch.h"

std::vector< size_t > FullSearch::minWay = std::vector< size_t >();
size_t FullSearch::minDist = 0;

std::pair< std::vector< size_t >, size_t > FullSearch::way(const Matrix< size_t >& distances)
{
    minDist = -1;

    std::vector< size_t > indexes;
    for (int i = 0; i < distances.size(); ++i)
        indexes.push_back(i);

    recursive(distances, indexes, 1);

    return std::pair< std::vector< size_t >, size_t >(minWay, minDist);
}

void FullSearch::recursive(const Matrix< size_t >& distances, std::vector< size_t >& indexes, size_t curIndex)
{
    if (curIndex >= indexes.size()) {
        size_t dist = distance(distances, indexes);

        if (dist < minDist) {
            minDist = dist;
            minWay = indexes;
        }

        return;
    }

    recursive(distances, indexes, curIndex + 1);

    for (int i = curIndex + 1; i < indexes.size(); ++i) {
        std::swap(indexes[curIndex], indexes[i]);
        recursive(distances, indexes, curIndex + 1);
        std::swap(indexes[curIndex], indexes[i]);
    }
}

size_t FullSearch::distance(const Matrix< size_t >& distances, const std::vector< size_t >& indexes)
{
    size_t dist = 0;
    for (int i = 0; i < indexes.size() - 1; ++i) {
        dist += distances[indexes[i]][indexes[i + 1]];
    }
    dist += distances[indexes[0]][indexes[indexes.size() - 1]];
    return dist;
}
