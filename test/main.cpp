#include <gtest/gtest.h>
#include "../include/StringNum.hpp"

TEST(StringNumTests, ADD_SIMPLE) {
    StringNum number = StringNum(std::string("1"));
    ASSERT_EQ((number + 1).toString(), StringNum("2").toString());
}

TEST(StringNumTests, ADD_MORE_THAN_TEN) {
    StringNum number = StringNum(std::string("10"));
    ASSERT_EQ((number + 2).toString(), StringNum("12").toString());
}

TEST(StringNumTests, ADD_NEW_DOZEN) {
    StringNum number = StringNum(std::string("10"));
    ASSERT_EQ((number + 10).toString(), StringNum("20").toString());
}

TEST(StringNumTests, ADD_NEW_DIGIT) {
    StringNum number = StringNum(std::string("9"));
    ASSERT_EQ((number + 2).toString(), StringNum("11").toString());
}

TEST(StringNumTests, ADD_CHANGE_SIGN_SIMPLE) {
    StringNum number = StringNum(std::string("-1"));
    ASSERT_EQ((number + 2).toString(), StringNum("1").toString());
}

TEST(StringNumTests, ADD_CHANGE_SIGN_MORE_THAN_TEN) {
    StringNum number = StringNum(std::string("-10"));
    ASSERT_EQ((number + 2).toString(), StringNum("-8").toString());
}

TEST(StringNumTests, ADD_CHANGE_SIGN_NEW_DOZEN) {
    StringNum number = StringNum(std::string("-6"));
    StringNum result = number + 6;

    ASSERT_EQ((number + 6).toString(), StringNum("0").toString());
}