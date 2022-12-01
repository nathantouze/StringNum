#include "../../include/StringNum.hpp"


void StringNum::operator++(int) {
    *this = *this + 1;
}