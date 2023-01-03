/*
** 2022
** StringNum.hpp
** File description:
** StringNum
*/

#ifndef STRINGNUM_HPP_
#define STRINGNUM_HPP_

#include <string>

class StringNum {
    public:
        StringNum(const std::string &number);
        StringNum(const unsigned long long int &number);
        StringNum(const long long int &number);
        StringNum(const int &number);
        ~StringNum();

        static std::string removeLeadingZeros(const std::string &str);
        static unsigned int countLeadingZeros(const std::string &str);

        void setNegative(bool negative);
        bool isNegative(const std::string &number) const;
        bool isNegative() const;
        bool isEven() const;
        const std::string &toString() const;
        const unsigned long long int toLong() const;
        const unsigned int length() const;
        void assign(const unsigned long long int &number);
        void assign(const long long int &number);
        void assign(const std::string &number);

        // Operators overloading
        bool operator>(const StringNum &other) const;
        bool operator>(const unsigned long long int &other) const;
        bool operator>(const std::string &other) const;

        bool operator>=(const StringNum &other) const;
        bool operator>=(const unsigned long long int &other) const;
        bool operator>=(const std::string &other) const;
            
        bool operator<(const StringNum &other) const;
        bool operator<(const unsigned long long int &other) const;
        bool operator<(const std::string &other) const;

        bool operator<=(const StringNum &other) const;
        bool operator<=(const unsigned long long int &other) const;
        bool operator<=(const std::string &other) const;

        bool operator==(const StringNum &other) const;
        bool operator==(const unsigned long long int &other) const;
        bool operator==(const std::string &other) const;

        bool operator!=(const StringNum &other) const;
        bool operator!=(const unsigned long long int &other) const;
        bool operator!=(const std::string &other) const;

        void operator++(int);

        StringNum operator+(const StringNum &other) const;
        StringNum operator+(const std::string &other) const;
        StringNum operator+(const short &other) const;
        StringNum operator+(const int &other) const;
        StringNum operator+(const unsigned int &other) const;
        StringNum operator+(const long &other) const;
        StringNum operator+(const long long int &other) const;
        StringNum operator+(const unsigned long long int &other) const;

        StringNum operator-(const StringNum &other) const;
        StringNum operator-(const std::string &other) const;
        StringNum operator-(const short &other) const;
        StringNum operator-(const int &other) const;
        StringNum operator-(const unsigned int &other) const;
        StringNum operator-(const long &other) const;
        StringNum operator-(const long long int &other) const;
        StringNum operator-(const unsigned long long int &other) const;

        StringNum operator*(const StringNum &other) const;
        StringNum operator*(const std::string &other) const;
        StringNum operator*(const short &other) const;
        StringNum operator*(const int &other) const;
        StringNum operator*(const unsigned int &other) const;
        StringNum operator*(const long &other) const;
        StringNum operator*(const long long int &other) const;
        StringNum operator*(const unsigned long long int &other) const;

        StringNum operator/(const StringNum &other) const;
        StringNum operator/(const std::string &other) const;
        StringNum operator/(const short &other) const;
        StringNum operator/(const int &other) const;
        StringNum operator/(const unsigned int &other) const;
        StringNum operator/(const long &other) const;
        StringNum operator/(const long long int &other) const;
        StringNum operator/(const unsigned long long int &other) const;
        
        StringNum operator%(const StringNum &other) const;
        StringNum operator%(const std::string &other) const;
        StringNum operator%(const short &other) const;
        StringNum operator%(const int &other) const;
        StringNum operator%(const unsigned int &other) const;
        StringNum operator%(const long &other) const;
        StringNum operator%(const long long int &other) const;
        StringNum operator%(const unsigned long long int &other) const;

        const bool &isOutOfRange() const;
    protected:
    private:
        void updateOutOfRange();
        bool isValidString(const std::string &number) const;
        bool firstBiggerOrEqual(const std::string &first, const std::string &second) const;
        std::string _numberStr;
        long long int _numberLong;
        bool _outOfRange;
};

#endif /* !STRINGNUM_HPP_ */
