#include "../../include/StringNum.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>


StringNum StringNum::operator+(const StringNum &other) const {

    StringNum ret = *this + other.toString();
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}

StringNum StringNum::operator+(const std::string &other) const {

    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }

    if (other == "0") {
        return StringNum(*this);
    }

    // Special cases
    if (!isNegative() && isNegative(other) && firstBiggerOrEqual(_numberStr, other.substr(1))) { // 5 + -3
        return StringNum(*this - other.substr(1));
    } else if (!isNegative() && isNegative(other) && !firstBiggerOrEqual(_numberStr, other.substr(1))) { // 3 + -5
        StringNum ret = StringNum(other.substr(1)) - *this;
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && !isNegative(other) && firstBiggerOrEqual(_numberStr.substr(1), other)) { // -5 + 3
        StringNum ret = StringNum(_numberStr.substr(1)) - StringNum(other);
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && !isNegative(other) && !firstBiggerOrEqual( _numberStr.substr(1), other)) { // -3 + 5
        return StringNum(other) - StringNum(_numberStr.substr(1));
    } else if (isNegative() && isNegative(other)) { // -3 + -5
        StringNum ret = StringNum(_numberStr.substr(1)) + StringNum(other.substr(1));
        ret.setNegative(true);
        return ret;
    }

    // Normal cases
    std::string tmp = this->_numberStr;
    std::string otherRev = other;
    std::reverse(otherRev.begin(), otherRev.end());
    std::reverse(tmp.begin(), tmp.end());

    int toAdd = 0;

    for (unsigned int i = 0; i < otherRev.length(); i++) {
        if (i >= tmp.length()) {
            tmp.append(std::to_string(std::stoi(otherRev.substr(i, 1)) + toAdd));
            toAdd = 0;
            continue;
        }
        int tmpInt = std::stoi(tmp.substr(i, 1)) + std::stoi(otherRev.substr(i, 1)) + toAdd;
        toAdd = (tmpInt - tmpInt % 10) / 10;
        tmp.replace(i, 1, std::to_string(tmpInt % 10));
    }
    if (toAdd != 0 && tmp.length() == otherRev.length()) {
        tmp.append(std::to_string(toAdd));
    }
    std::reverse(tmp.begin(), tmp.end());
    if (tmp == "-0" || tmp == "") {
        tmp = "0";
    }
    StringNum ret = tmp;
    return ret;
}


StringNum StringNum::operator+(const short &other) const {
    StringNum ret = *this + std::to_string(other);
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}

StringNum StringNum::operator+(const int &other) const {
    StringNum ret = *this + std::to_string(other);
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}

StringNum StringNum::operator+(const unsigned int &other) const {    
    StringNum ret = *this + std::to_string(other);
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}

StringNum StringNum::operator+(const long &other) const {
    StringNum ret = *this + std::to_string(other);
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}

StringNum StringNum::operator+(const long long int &other) const {
    StringNum ret = *this + std::to_string(other);
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}

StringNum StringNum::operator+(const unsigned long long int &other) const {
    StringNum ret = *this + std::to_string(other);
    if (ret.toString() == "") {
        ret.assign("0");
    }
    return ret;
}