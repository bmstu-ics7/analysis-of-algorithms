#include "AntSearch.h"
#include <iostream>
#include <cmath>

std::pair< std::vector< size_t >, size_t > AntSearch::way(const Matrix< size_t >& distances,
                                                          double alpha,
                                                          double beta,
                                                          double rho,
                                                          double tmax)
{
    srand(time(NULL));

    Matrix< double > pheromone(distances.size(), 0.1);

    size_t minDist = -1;
    std::vector< size_t > minWay(distances.size());

    for (int time = 0; time < tmax; ++time) {
        std::vector< int > ants(distances.size());
        std::vector< std::vector< double > > delta;

        for (int i = 0; i < distances.size(); ++i) {
            ants[i] = i + 1;
            delta.push_back(std::vector< double >(distances.size()));
        }

        for (int ant = 0; ant < ants.size(); ++ant) {
            int count = 0;
            std::vector< int > cities(distances.size());
            std::vector< size_t > way(distances.size());

            cities[ant] = 1;
            way[0] = ant;

            int len = 0;

            while (count + 1 < distances.size()) {
                std::vector< double > p(distances.size());

                for (int j = 0; j < distances.size(); ++j) {
                    if (cities[j] == 0) {
                        p[j] = std::pow(pheromone[way[count]][j], alpha) *
                               std::pow(distances[way[count]][j], beta);

                        double all = 0;

                        for (int q = 0; q < count; ++q) {
                            all += std::pow(pheromone[way[q]][j], alpha) *
                                   std::pow(distances[way[q]][j], beta);
                        }

                        p[j] /= all;
                    } else {
                        p[j] = 0;
                    }
                }

                std::vector< int > arr(distances.size() - count - 1);
                int cyc = 0;

                for (int i = 0; i < distances.size(); ++i) {
                    if (cities[i] == 0) {
                        arr[cyc] = i;
                        ++cyc;
                    }
                }

                int rdm = rand() % (distances.size() - count - 1);
                len += distances[way[count]][arr[rdm]];
                ++count;
                way[count] = arr[rdm];
                cities[arr[rdm]] = 1;
            }

            len += distances[way[0]][way[distances.size() - 1]];

            for (int i = 0; i < distances.size() - 1; ++i) {
                delta[way[i]][way[i + 1]] += minDist / len;
                delta[way[i + 1]][way[i]] += minDist / len;
            }

            if (len < minDist) {
                minDist = len;
                minWay = way;
            }
        }

        for (int i = 0; i < distances.size() - 1; ++i) {
            for (int j = i + 1; j < distances.size(); ++j) {
                pheromone[i][j] *= (1 - rho);
                pheromone[i][j] += delta[i][j];
            }
        }
    }

    return std::pair< std::vector< size_t >, size_t >(minWay, minDist);
}
