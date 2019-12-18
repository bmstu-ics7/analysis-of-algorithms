#include "BoilerMyr.h"
#include <iostream>

int BoilerMyr::find(const std::string& str, const std::string& substr)
{
    if (substr.size() > str.size()) return -1;

    std::vector< int > offset;

    for (int i = 0; i <= 255; ++i) {
        offset.push_back(int(substr.size()));
    }

    for (int i = 0; i < substr.size() - 1; ++i) {
        offset[int(substr[i])] = substr.size() - i - 1;
    }

    int i = int(substr.size()) - 1;
    int j = i;
    int k = i;

    while (j > 0 && i < int(str.size())) {
        j = int(substr.size()) - 1;
        k = i;

        while (j >= 0 && str[k] == substr[j]) {
            --k;
            --j;
        }

        i += offset[int(str[i])];
    }

    if (k > int(str.size()) - int(substr.size())) return -1;

    return k + 1;
}
