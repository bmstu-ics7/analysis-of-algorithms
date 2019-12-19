#include "KnuthMorrisPratt.h"

int KnuthMorrisPratt::find(const std::string& str, const std::string& substr)
{
    if (str.size() == 0 || substr.size() == 0) return -1;
    if (substr.size() > str.size()) return -1;

    std::vector< int > fail = makeFail(substr);

    int sub = 0;
    int txt = 0;

    while (txt < int(str.size()) && sub < int(substr.size())) {
        if (sub == -1 || str[txt] == substr[sub]) {
            ++txt;
            ++sub;
        } else {
            sub = fail[sub];
        }
    }

    if (sub >= substr.size())
        return txt - substr.size();

    return -1;
}

std::vector< int > KnuthMorrisPratt::makeFail(const std::string& substr)
{
    std::vector< int > fail(substr.size());

    fail[0] = -1;

    for (int i = 1; i < fail.size(); ++i) {
        int temp = fail[i - 1];

        while (temp > -1 && substr[temp] != substr[i - 1]) {
            temp = fail[temp];
        }

        fail[i] = temp + 1;
    }

    return fail;
}
