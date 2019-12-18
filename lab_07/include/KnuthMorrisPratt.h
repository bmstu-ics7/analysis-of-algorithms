#ifndef __KNUTHMORRISPRATT_H
#define __KNUTHMORRISPRATT_H

#include <string>
#include <vector>

class KnuthMorrisPratt
{
public:
    static int find(const std::string& str, const std::string& substr);

private:
    static std::vector< int > makeFail(const std::string& str);
};

#endif // __KNUTHMORRISPRATT_H
