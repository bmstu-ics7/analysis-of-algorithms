#include <iostream>

#include "Lmatrix.h"
#include "DLmatrix.h"
#include "DLrecursive.h"

int main()
{
    std::cout << "Lmatrix:" << std::endl;
    std::cout << "aaa -> aa" << std::endl << Lmatrix::find("aaa", "aa") << std::endl;
    std::cout << "skat -> kot" << std::endl << Lmatrix::find("skat", "kot") << std::endl;
    std::cout << "Hello -> Hello" << std::endl << Lmatrix::find("Hello", "Hello") << std::endl;
    std::cout << "Abc -> aBC" << std::endl << Lmatrix::find("Abc", "aBC") << std::endl;
    std::cout << "dagestan -> arestant" << std::endl << Lmatrix::find("dagestan", "arestant") << std::endl;
    std::cout << "ab -> ba" << std::endl << Lmatrix::find("ab", "ba") << std::endl;
    std::cout << "abcdefgh -> badcfehg" << std::endl << Lmatrix::find("abcdefgh", "badcfehg") << std::endl;
    std::cout << "qwerty -> qwrety" << std::endl << Lmatrix::find("qwerty", "qwrety") << std::endl;
    std::cout << std::endl;

    std::cout << "DLmatrix:" << std::endl;
    std::cout << "aaa -> aa" << std::endl << DLmatrix::find("aaa", "aa") << std::endl;
    std::cout << "skat -> kot" << std::endl << DLmatrix::find("skat", "kot") << std::endl;
    std::cout << "Hello -> Hello" << std::endl << DLmatrix::find("Hello", "Hello") << std::endl;
    std::cout << "Abc -> aBC" << std::endl << DLmatrix::find("Abc", "aBC") << std::endl;
    std::cout << "dagestan -> arestant" << std::endl << DLmatrix::find("dagestan", "arestant") << std::endl;
    std::cout << "ab -> ba" << std::endl << DLmatrix::find("ab", "ba") << std::endl;
    std::cout << "abcdefgh -> badcfehg" << std::endl << DLmatrix::find("abcdefgh", "badcfehg") << std::endl;
    std::cout << "qwerty -> qwrety" << std::endl << DLmatrix::find("qwerty", "qwrety") << std::endl;
    std::cout << std::endl;

    std::cout << "DLrecursive:" << std::endl;
    std::cout << "aaa -> aa" << std::endl << DLrecursive::find("aaa", "aa") << std::endl;
    std::cout << "skat -> kot" << std::endl << DLrecursive::find("skat", "kot") << std::endl;
    std::cout << "Hello -> Hello" << std::endl << DLrecursive::find("Hello", "Hello") << std::endl;
    std::cout << "Abc -> aBC" << std::endl << DLrecursive::find("Abc", "aBC") << std::endl;
    std::cout << "dagestan -> arestant" << std::endl << DLrecursive::find("dagestan", "arestant") << std::endl;
    std::cout << "ab -> ba" << std::endl << DLrecursive::find("ab", "ba") << std::endl;
    std::cout << "abcdefgh -> badcfehg" << std::endl << DLrecursive::find("abcdefgh", "badcfehg") << std::endl;
    std::cout << "qwerty -> qwrety" << std::endl << DLrecursive::find("qwerty", "qwrety") << std::endl;
    std::cout << std::endl;
    return 0;
}
