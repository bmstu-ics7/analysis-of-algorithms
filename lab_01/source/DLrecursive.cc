#include "DLrecursive.h"

int DLrecursive::find(std::string s1, std::string s2)
{
    if (s1.size() == 0) return s2.size();
    if (s2.size() == 0) return s1.size();

    return std::min(
            std::min(
                find(s1.substr(0, s1.size() - 1), s2) + 1,
                find(s1, s2.substr(0, s2.size() - 1)) + 1
            ),
            std::min(
                find(s1.substr(0, s1.size() - 1), 
                     s2.substr(0, s2.size() - 1)) + 
                (s1[s1.size() - 1] == s2[s2.size() - 1] ? 0 : 1),

                (s1.size() > 1 && 
                 s2.size() > 1 && 
                 s1[s1.size() - 2] == s2[s2.size() - 1] && 
                 s1[s1.size() - 1] == s2[s2.size() - 2] ?
                 find(s1.substr(0, s1.size() - 2), 
                      s2.substr(0, s2.size() - 2)) : 
                    int(std::max(s1.size(), s2.size()))) + 1
            )
        );
}
