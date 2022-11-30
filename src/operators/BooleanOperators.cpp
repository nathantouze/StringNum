#include "../../include/StringNum.hpp"
#include <stdexcept>


bool StringNum::operator>=(const StringNum &other) const {
    if (this > &other || this == &other) {
        return true;
    } else {
        return false;
    }
}

bool StringNum::operator>=(const unsigned long long int &other) const {
    if (*this > other || *this == other) {
        return true;
    } else {
        return false;
    }
}

bool StringNum::operator>=(const std::string &other) const {
    if (*this > other || *this == other) {
        return true;
    } else {
        return false;
    }
}

bool StringNum::operator>(const unsigned long long int &other) const {
    
    if (isOutOfRange()) {
        throw std::out_of_range("StringNum object is out of range.");
    }
    return _numberLong > other;
}

bool StringNum::operator>(const std::string &other) const {

    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }
    if (this->isNegative() && !isNegative(other)) {
        return false;
    }
    if (!this->isNegative() && isNegative(other)) {
        return true;
    }
    if (this->isNegative() && isNegative(other)) {
        if (this->_numberStr.length() > other.length()) {
            return false;
        }
        if (this->_numberStr.length() < other.length()) {
            return true;
        }
        for (int i = 1; i < this->_numberStr.length(); i++) {
            if (this->_numberStr[i] > other[i]) {
                return false;
            }
            if (this->_numberStr[i] < other[i]) {
                return true;
            }
        }
        return false;
    }
    if (this->_numberStr.length() > other.length()) {
        return true;
    }
    if (this->_numberStr.length() < other.length()) {
        return false;
    }
    for (int i = 0; i < this->_numberStr.length(); i++) {
        if (this->_numberStr[i] > other[i]) {
            return true;
        }
        if (this->_numberStr[i] < other[i]) {
            return false;
        }
    }
    return false;
}

bool StringNum::operator>(const StringNum &other) const {

    if (this->isNegative() && !other.isNegative()) {
        return false;
    } else if (!this->isNegative() && other.isNegative()) {
        return true;
    } else if (this->isNegative() && other.isNegative()) {
        if (this->_numberStr.length() > other.toString().length()) {
            return false;
        } else if (this->_numberStr.length() < other.toString().length()) {
            return true;
        } else {
            for (int i = 0; i < this->_numberStr.length(); i++) {
                if (this->_numberStr[i] > other.toString()[i]) {
                    return false;
                } else if (this->_numberStr[i] < other.toString()[i]) {
                    return true;
                }
            }
        }
    } else {
        if (this->_numberStr.length() > other.toString().length()) {
            return true;
        } else if (this->_numberStr.length() < other.toString().length()) {
            return false;
        } else {
            for (int i = 0; i < this->_numberStr.length(); i++) {
                if (this->_numberStr[i] > other.toString()[i]) {
                    return true;
                } else if (this->_numberStr[i] < other.toString()[i]) {
                    return false;
                }
            }
        }
    }
    return false;
}


bool StringNum::operator<=(const StringNum &other) const {
    if (this < &other || this == &other) {
        return true;
    } else {
        return false;
    }
}

bool StringNum::operator<=(const unsigned long long int &other) const {
    if (*this < other || *this == other) {
        return true;
    } else {
        return false;
    }
}

bool StringNum::operator<=(const std::string &other) const {
    if (*this < other || *this == other) {
        return true;
    } else {
        return false;
    }
}

bool StringNum::operator<(const unsigned long long int &other) const {
    
    if (isOutOfRange()) {
        throw std::out_of_range("StringNum object is out of range.");
    }
    return _numberLong < other;
}

bool StringNum::operator<(const std::string &other) const {
    
    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }
    if (this->isNegative() && !isNegative(other)) {
        return true;
    }
    if (!this->isNegative() && isNegative(other)) {
        return false;
    }
    if (this->isNegative() && isNegative(other)) {
        if (this->_numberStr.length() > other.length()) {
            return true;
        }
        if (this->_numberStr.length() < other.length()) {
            return false;
        }
        for (int i = 1; i < this->_numberStr.length(); i++) {
            if (this->_numberStr[i] > other[i]) {
                return true;
            }
            if (this->_numberStr[i] < other[i]) {
                return false;
            }
        }
        return false;
    }
    if (this->_numberStr.length() > other.length()) {
        return false;
    }
    if (this->_numberStr.length() < other.length()) {
        return true;
    }
    for (int i = 0; i < this->_numberStr.length(); i++) {
        if (this->_numberStr[i] > other[i]) {
            return false;
        }
        if (this->_numberStr[i] < other[i]) {
            return true;
        }
    }
    return false;
}

bool StringNum::operator<(const StringNum &other) const {
        
        if (this->isNegative() && !other.isNegative()) {
            return true;
        } else if (!this->isNegative() && other.isNegative()) {
            return false;
        } else if (this->isNegative() && other.isNegative()) {
            if (this->_numberStr.length() > other.toString().length()) {
                return true;
            } else if (this->_numberStr.length() < other.toString().length()) {
                return false;
            } else {
                for (int i = 0; i < this->_numberStr.length(); i++) {
                    if (this->_numberStr[i] > other.toString()[i]) {
                        return true;
                    } else if (this->_numberStr[i] < other.toString()[i]) {
                        return false;
                    }
                }
            }
        } else {
            if (this->_numberStr.length() > other.toString().length()) {
                return false;
            } else if (this->_numberStr.length() < other.toString().length()) {
                return true;
            } else {
                for (int i = 0; i < this->_numberStr.length(); i++) {
                    if (this->_numberStr[i] > other.toString()[i]) {
                        return false;
                    } else if (this->_numberStr[i] < other.toString()[i]) {
                        return true;
                    }
                }
            }
        }
        return false;
}

bool StringNum::operator==(const unsigned long long int &other) const {
    
    if (isOutOfRange()) {
        throw std::out_of_range("StringNum object is out of range.");
    }
    return _numberLong == other;
}

bool StringNum::operator==(const std::string &other) const {
    
    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }
    return _numberStr == other;
}

bool StringNum::operator==(const StringNum &other) const {

    return _numberStr == other.toString();
}

bool StringNum::operator!=(const unsigned long long int &other) const {
    
    if (isOutOfRange()) {
        throw std::out_of_range("StringNum object is out of range.");
    }
    return _numberLong != other;
}

bool StringNum::operator!=(const std::string &other) const {
    
    if (!isValidString(other)) {
        throw std::invalid_argument("\"" + other + "\" is not a valid string number");
    }
    return _numberStr != other;
}

bool StringNum::operator!=(const StringNum &other) const {

    return _numberStr != other.toString();
}
