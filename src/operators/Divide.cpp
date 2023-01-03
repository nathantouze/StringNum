#include "../../include/StringNum.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

StringNum StringNum::operator/(const StringNum &other) const {
    return StringNum(*this / other.toString());
}

StringNum StringNum::operator/(const std::string &other) const {

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
    if (!isNegative() && isNegative(other)) { // 5 / -3
        StringNum ret =  *this / other.substr(1);
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && !isNegative(other)) { // -5 / 3
        StringNum ret = StringNum(_numberStr.substr(1)) / other;
        ret.setNegative(true);
        return ret;
    } else if (isNegative() && isNegative(other)) { // -5 / -3
        return StringNum(_numberStr.substr(1)) / other.substr(1);
    }

    // Simple cases 2
    if (other == "1") {
        return StringNum(_numberStr);
    }


    // Normal cases
    std::string tmp = this->_numberStr;
    std::string result = "";
    std::string curr = "";
    
    for (int i = 0; i < tmp.size(); i++) {
        curr += tmp[i];
        int j = 0;
        curr = StringNum(curr).toString();
        while ((curr.size() > other.size() || (curr.size() == other.size() && StringNum(curr) >= other)) && !isNegative(curr)) {
            StringNum currTemp = StringNum(curr) - other;
            if (currTemp.isNegative()) {
                currTemp.setNegative(false);
            }
            curr = currTemp.toString();
            j++;
        }
        result += (char)(j + '0');
    }
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return StringNum(result);
}

StringNum StringNum::operator/(const short &other) const {
    return *this / std::to_string(other);
}

StringNum StringNum::operator/(const int &other) const {
    return *this / std::to_string(other);
}

StringNum StringNum::operator/(const unsigned int &other) const {
    return *this / std::to_string(other);
}

StringNum StringNum::operator/(const long &other) const {
    return *this / std::to_string(other);
}

StringNum StringNum::operator/(const long long int &other) const {
    return *this / std::to_string(other);
}

StringNum StringNum::operator/(const unsigned long long int &other) const {
    return *this / std::to_string(other);
}