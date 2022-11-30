#include "../../include/StringNum.hpp"
#include <stdexcept>
#include <iostream>

StringNum StringNum::operator-(const StringNum &other) const {
    return StringNum(*this - other.toString());
}

StringNum StringNum::operator-(const std::string &other) const {

    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }
    if (other == "0") {
        return StringNum(*this);
    }

    // Special cases
    if (!isNegative() && isNegative(other)) { // 5 - -3
        return StringNum(*this + other.substr(1));
    } else if (isNegative() && !isNegative(other)) { // -5 - 3
        StringNum ret = StringNum(other) + _numberStr.substr(1);
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && isNegative(other) && firstBigger(_numberStr, other)) { // -5 - -3
        StringNum ret = StringNum(other.substr(1)) - _numberStr.substr(1);
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && isNegative(other) && !firstBigger(_numberStr, other)) { // -3 - -5
        return StringNum(other.substr(1)) - _numberStr.substr(1);
    } else if (!firstBigger(_numberStr, other)) { // 3 - 5
        StringNum ret = StringNum(other) - _numberStr;
        ret.setNegative(true);
        return ret;
    }

    // Normal cases
    std::string tmp = this->_numberStr;
    std::string otherRev = other;
    std::reverse(otherRev.begin(), otherRev.end());
    std::reverse(tmp.begin(), tmp.end());
    int toSub = 0;

    for (unsigned int i = 0; i < tmp.length(); i++) {
        if (i >= otherRev.length()) {
            break;
        }
        int tmpInt = std::stoi(tmp.substr(i, 1)) - std::stoi(otherRev.substr(i, 1)) - toSub;
        if (tmpInt < 0) {
            tmpInt += 10;
            toSub = 1;
        } else {
            toSub = 0;
        }
        tmp.replace(i, 1, std::to_string(tmpInt));
    }
    std::reverse(tmp.begin(), tmp.end());
    
    return StringNum(tmp);
}

StringNum StringNum::operator-(const short &other) const {
    return *this - std::to_string(other);
}

StringNum StringNum::operator-(const int &other) const {
    return *this - std::to_string(other);
}

StringNum StringNum::operator-(const unsigned int &other) const {
    return *this - std::to_string(other);
}

StringNum StringNum::operator-(const long &other) const {
    return *this - std::to_string(other);
}

StringNum StringNum::operator-(const long long int &other) const {
    return *this - std::to_string(other);
}

StringNum StringNum::operator-(const unsigned long long int &other) const {
    return *this - std::to_string(other);
}