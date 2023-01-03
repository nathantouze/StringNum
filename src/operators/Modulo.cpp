#include "../../include/StringNum.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

StringNum StringNum::operator%(const StringNum &other) const {
    return StringNum(*this % other.toString());
}

StringNum StringNum::operator%(const std::string &other) const {

    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }

    // Simple cases
    if (other == "0") {
        throw std::invalid_argument("Division by zero");
    } else if (_numberStr == "0") {
        return StringNum("0");
    }

    // Special cases
    if (!isNegative() && isNegative(other)) { // 5 % -3
        return *this % other.substr(1);
    } else if (isNegative() && !isNegative(other)) { // -5 % 3
        StringNum ret = StringNum(_numberStr.substr(1)) % other;
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && isNegative(other)) { // -5 % -3
        StringNum ret = StringNum(_numberStr.substr(1)) % other.substr(1);
        ret.setNegative(true);
        return ret;
    }

    // Simple cases 2
    if (other == "1") {
        return StringNum("0");
    }


    // Normal cases
    std::string tmp = this->_numberStr;
    std::string result = "";
    std::string curr = "";
    
    for (int i = 0; i < tmp.size(); i++) {
        curr += tmp[i];
        curr = StringNum(curr).toString();
        while (curr.size() > other.size() || (curr.size() == other.size() && StringNum(curr) >= other)) {
            StringNum currTemp = StringNum(curr) - other;
            if (currTemp.isNegative()) {
                currTemp.setNegative(false);
            }
            curr = currTemp.toString();
        }
    }
    return StringNum(curr);
}

StringNum StringNum::operator%(const short &other) const {
    return *this % std::to_string(other);
}

StringNum StringNum::operator%(const int &other) const {
    return *this % std::to_string(other);
}

StringNum StringNum::operator%(const unsigned int &other) const {
    return *this % std::to_string(other);
}

StringNum StringNum::operator%(const long &other) const {
    return *this % std::to_string(other);
}

StringNum StringNum::operator%(const long long int &other) const {
    return *this % std::to_string(other);
}

StringNum StringNum::operator%(const unsigned long long int &other) const {
    return *this % std::to_string(other);
}