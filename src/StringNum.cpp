#include "../include/StringNum.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>



const unsigned int StringNum::length() const {
    return _numberStr.length();
}

/*
    Set new sign to the number
*/
void StringNum::setNegative(bool negative) {
    if (isNegative() != negative) {
        if (negative && _numberStr != "0") {
            _numberStr = "-" + _numberStr;
        } else if (_numberStr == "0") {
            return;
        } 
        else {
            _numberStr = _numberStr.substr(1);
        }
        if (!isOutOfRange()) {
            _numberLong = -_numberLong;
        }
    }
}

/*
    The two strings must be correct positive numbers (no minus sign, no leading zeros)
*/
bool StringNum::firstBiggerOrEqual(const std::string &first, const std::string &second) const {
    
    if (!isValidString(first) || !isValidString(second) || isNegative(first) || isNegative(second)) {
        throw std::invalid_argument("The two strings must be correct positive numbers (no minus sign, no leading zeros)");
    }
    if (first.size() > second.size())
        return true;
    else if (first.size() < second.size())
        return false;
    else {
        for (size_t i = 0; i < first.size(); i++) {
            if (first[i] > second[i])
                return true;
            else if (first[i] < second[i])
                return false;
        }
    }
    return true;
}


bool StringNum::isValidString(const std::string &number) const {
    if (number.length() == 0 || (number.length() == 1 && number[0] == '-')) {
        return false;
    }
    int i = 0;
    if (number[0] == '-') {
        i = 1;
    }
    if (number[i] == '0' && number.length() > 1) {
        return false;
    }
    for (; i < number.length(); i++) {
        if (number[i] < '0' || number[i] > '9')
            return false;
    }
    return true;
}

bool StringNum::isNegative(const std::string &number) const {
    if (number[0] == '-') {
        return true;
    }
    return false;
}

bool StringNum::isNegative() const {
    return this->_numberStr[0] == '-';
}

void StringNum::assign(const long long int &number) {
    _numberLong = number;
    _numberStr = std::to_string(number);
    updateOutOfRange();
}

void StringNum::assign(const unsigned long long int &number) {
    _numberLong = number;
    _numberStr = std::to_string(number);
    updateOutOfRange();
}

void StringNum::assign(const std::string &number) {
    _numberStr = number;
    std::istringstream in(number);
    in >> _numberLong;
    updateOutOfRange();
}

const unsigned long long int StringNum::toLong() const {
    return _numberLong;
}

const std::string &StringNum::toString() const {
    return _numberStr;
}

bool StringNum::isEven() const {
    
    int last = std::stoi(_numberStr.substr(_numberStr.length() - 1));
    return last % 2 == 0;
}

void StringNum::updateOutOfRange() {
    if (toString() != std::to_string(_numberLong)) {
        _outOfRange = true;
    } else {
        _outOfRange = false;
    }
}

const bool &StringNum::isOutOfRange() const {
    return _outOfRange;
}


unsigned int StringNum::countLeadingZeros(const std::string &number) {
    
    unsigned int result = 0;

    int idx_rm = 0;
    if (number.at(0) == '-') {
        idx_rm = 1;
    }
    for (std::size_t i = idx_rm; i < number.length(); i++) {
        if (number.at(i) == '0') {
            result++;
        } else {
            break;
        }
    }
    return result;
}

std::string StringNum::removeLeadingZeros(const std::string &number) {
    std::string result = number;

    int idx_rm = 0;
    if (result.at(0) == '-') {
        idx_rm = 1;
    }
    while (result.length() > idx_rm + 1 && result.at(idx_rm) == '0') {
        result = result.replace(idx_rm, 1, "");
    }
    return result;
}

StringNum::StringNum(const int &number) 
{
    const long long int numberLong = number;
    assign(numberLong);
    if (_numberStr == "") {
        _numberStr = "0";
    }
    updateOutOfRange();
}

StringNum::StringNum(const long long int &number) 
{
    assign(number);
    if (_numberStr == "") {
        _numberStr = "0";
    }
    updateOutOfRange();
}

StringNum::StringNum(const unsigned long long int &number)
{
    assign(number);
    if (_numberStr == "") {
        _numberStr = "0";
    }
    updateOutOfRange();
}

StringNum::StringNum(const std::string &number)
{
    std::string cleanStr = removeLeadingZeros(number);
    if (!isValidString(cleanStr)) {
        throw std::invalid_argument("'" + number + "' is not a valid string number");
    }
    assign(cleanStr);
    if (_numberStr == "") {
        _numberStr = "0";
    }
    updateOutOfRange();
}

StringNum::~StringNum()
{
}