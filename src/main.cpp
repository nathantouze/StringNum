#include "StringNum.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av) {

    if (ac < 2) {
        std::cerr << "No argument: please insert a starting number." << std::endl;
        return 1;
    }
    std::cout << "Starting number: " << av[1] << std::endl;
    StringNum number = StringNum(std::string(av[1]));
    std::cout << "Starting number: " << number.toString() << std::endl;
    std::cout << number.toString() << " + 1: " << (number + 1).toString() << std::endl;
    std::cout << number.toString() << " - 1: " << (number - 1).toString() << std::endl;
    return 0;
}