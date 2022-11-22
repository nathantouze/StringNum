#include "StringNum.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av) {

    if (ac < 2) {
        std::cerr << "No argument: please insert a starting number." << std::endl;
        return 1;
    }
    StringNum number = StringNum(std::string(av[1]));
    return 0;
}