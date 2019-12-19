#include "BoilerMyr.h"
#include <iostream>

int BoilerMyr::find(const std::string& str, const std::string& substr)
{
    if (str.size() == 0 || substr.size() == 0) return -1;
    if (substr.size() > str.size()) return -1;

    std::vector< int > offset;

    for (int i = 0; i <= 512; ++i) {
        offset.push_back(int(substr.size()));
    }

    for (int i = 0; i < substr.size() - 1; ++i) {
        offset[int(substr[i])] = substr.size() - i - 1;
    }

    int i = int(substr.size()) - 1;
    int sub = i;
    int txt = i;

    while (sub >= 0 && i <= int(str.size())) {
        sub = int(substr.size()) - 1;
        txt = i;

        while (sub >= 0 && str[txt] == substr[sub]) {
            --sub;
            --txt;
        }

        i += offset[int(str[i])];
    }

    if (txt > int(str.size()) - int(substr.size())) return -1;

    return txt + 1;
}
