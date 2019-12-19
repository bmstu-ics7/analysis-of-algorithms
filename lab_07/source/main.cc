#include <iostream>
#include "KnuthMorrisPratt.h"
#include "BoilerMyr.h"

#define BOLD_ON  "\e[1m"
#define BOLD_OFF "\e[0m"

int main(int argc, char* argv[])
{
    if (argc != 3) return -1;

    std::cout << BOLD_ON << "Knuth-Morris-Pratt: " << BOLD_OFF;
    std::cout << KnuthMorrisPratt::find(argv[1], argv[2]) << std::endl;

    std::cout << BOLD_ON << "Boiler-Myr: " << BOLD_OFF;
    std::cout << BoilerMyr::find(argv[1], argv[2]) << std::endl;

    return 0;
}
