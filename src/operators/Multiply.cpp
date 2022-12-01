#include "../../include/StringNum.hpp"
#include <stdexcept>
#include <algorithm>


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
    int toAdd = 0;
    std::string tmp = this->_numberStr;
    std::string otherRev = other;
    std::reverse(otherRev.begin(), otherRev.end());
    std::reverse(tmp.begin(), tmp.end());

    for (unsigned int i = 0; i < otherRev.length(); i++) {
        for (unsigned int j = 0; j < tmp.length(); j++) {
            int tmpInt = std::stoi(tmp.substr(j, 1)) * std::stoi(otherRev.substr(i, 1)) + toAdd;
            toAdd = (tmpInt - tmpInt % 10) / 10;
            tmp.replace(j, 1, std::to_string(tmpInt % 10));
        }
        if (toAdd != 0) {
            tmp.append(std::to_string(toAdd));
            toAdd = 0;
        }
        tmp.append(std::string(i, '0'));
    }
    std::reverse(tmp.begin(), tmp.end());
    return StringNum(tmp);
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