#include "../../include/StringNum.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>


StringNum StringNum::operator*(const StringNum &other) const {
    return *this * other.toString();
}

StringNum StringNum::operator*(const std::string &other) const {

    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }
    if (StringNum(other).toString() == "0") {
        return StringNum("0");
    } else if (StringNum(other).toString() == "1") {
        return StringNum(*this);
    } else if (StringNum(other).toString() == "-1") {
        StringNum ret = StringNum(*this);
        ret.setNegative(!ret.isNegative());
        return ret;
    }

    // Special cases
    if (isNegative() && !isNegative(other)) {
        StringNum ret = StringNum(_numberStr.substr(1)) * StringNum(other);
        ret.setNegative(true);
        return ret;
    } else if (!isNegative() && isNegative(other)) {
        StringNum ret = StringNum(_numberStr) * StringNum(other.substr(1));
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && isNegative(other)) {
        return StringNum(_numberStr.substr(1)) * StringNum(other.substr(1));
    }

    // Normal cases
    StringNum tmp = _numberStr;
    StringNum save = _numberStr;

    for (StringNum i = 1; i < other; i++) {
        tmp = tmp + save;
    }
    return tmp;
}

StringNum StringNum::operator*(const short &other) const {
    return *this * std::to_string(other);
}

StringNum StringNum::operator*(const int &other) const {
    return *this * std::to_string(other);
}

StringNum StringNum::operator*(const unsigned int &other) const {
    return *this * std::to_string(other);
}

StringNum StringNum::operator*(const long &other) const {
    return *this * std::to_string(other);
}

StringNum StringNum::operator*(const long long int &other) const {
    return *this * std::to_string(other);
}

StringNum StringNum::operator*(const unsigned long long int &other) const {
    return *this * std::to_string(other);
}