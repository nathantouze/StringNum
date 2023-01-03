#include <gtest/gtest.h>
#include "../include/StringNum.hpp"


TEST(StringNumStatic, REMOVE_LEADING_ZEROS) {
    ASSERT_EQ(StringNum::removeLeadingZeros("00"), "0");
}

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

TEST(StringNumTests, ADD_NEW_DOZEN_HARD) {
    StringNum number = StringNum(std::string("222"));
    ASSERT_EQ((number + 78).toString(), StringNum("300").toString());
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

TEST(StringNumTests, SUB_SIMPLE) {
    StringNum number = std::string("123456");
    ASSERT_EQ((number - 1).toString(), StringNum("123455").toString());
}

TEST(StringNumTests, SUB_MORE_THAN_TEN) {
    StringNum number = std::string("123456");
    ASSERT_EQ((number - 11).toString(), StringNum("123445").toString());
}

TEST(StringNumTests, SUB_NEW_DOZEN) {
    StringNum number = std::string("123450");
    ASSERT_EQ((number - 10).toString(), StringNum("123440").toString());
}

TEST(StringNumTests, SUB_NEW_DIGIT) {
    StringNum number = std::string("-1");
    ASSERT_EQ((number - 16).toString(), StringNum("-17").toString());
}

TEST(StringNumTests, SUB_CHANGE_SIMPLE_SIGN) {
    StringNum number = std::string("-1");
    ASSERT_EQ((number - (-2)).toString(), StringNum("1").toString());
}

TEST(StringNumTests, SUB_CHANGE_MORE_THAN_TEN_SIGN) {
    StringNum number = std::string("-10");
    ASSERT_EQ((number - (-2)).toString(), StringNum("-8").toString());
}

TEST(StringNumTests, SUB_CHANGE_NEW_DOZEN_SIGN) {
    StringNum number = std::string("-6");
    StringNum result = number - (-6);
    ASSERT_EQ((number - (-6)).toString(), StringNum("0").toString());
}

TEST(StringNumTests, SUB_CHANGE_NEW_DIGIT_SIGN) {
    StringNum number = std::string("-1");
    ASSERT_EQ((number - (-16)).toString(), StringNum("15").toString());
}

TEST(StringNumTests, MUL_SIMPLE) {
    StringNum number = 8;
    ASSERT_EQ((number * 2).toString(), StringNum("16").toString());
}

TEST(StringNumTests, MUL_ONE_POS) {
    StringNum number = 987652123456;
    ASSERT_EQ((number * 1).toString(), StringNum("987652123456").toString());
}

TEST(StringNumTests, MUL_ONE_NEG) {
    StringNum number = 23986345;
    ASSERT_EQ((number * -1).toString(), StringNum("-23986345").toString());
}

TEST(StringNumTests, MUL_ZERO) {
    StringNum number = 23986345;
    ASSERT_EQ((number * 0).toString(), StringNum("0").toString());
}

TEST(StringNumTests, MUL_MORE_THAN_TEN) {
    StringNum number = 23986345;
    ASSERT_EQ((number * 11).toString(), StringNum("263849795").toString());
}

TEST(StringNumTests, MUL_NEW_DOZEN) {
    StringNum number = 23986345;
    ASSERT_EQ((number * 10).toString(), StringNum("239863450").toString());
}

TEST(StringNumTests, MUL_FIRST_NEG) {
    StringNum number = -23986345;
    ASSERT_EQ((number * 10).toString(), StringNum("-239863450").toString());
}

TEST(StringNumTests, MUL_SECOND_NEG) {
    StringNum number = 23986345;
    ASSERT_EQ((number * -10).toString(), StringNum("-239863450").toString());
}

TEST(StringNumTests, MUL_BOTH_NEG) {
    StringNum number = -23986345;
    ASSERT_EQ((number * -10).toString(), StringNum("239863450").toString());
}

TEST(StringNumTests, DIV_SIMPLE) {
    StringNum number = 16;
    ASSERT_EQ((number / 2).toString(), StringNum("8").toString());
}

TEST(StringNumTests, DIV_ONE_POS) {
    StringNum number = 987652123456;
    ASSERT_EQ((number / 1).toString(), StringNum("987652123456").toString());
}

TEST(StringNumTests, DIV_ONE_NEG) {
    StringNum number = 23986345;
    ASSERT_EQ((number / -1).toString(), StringNum("-23986345").toString());
}

TEST(StringNumTests, DIV_ZERO) {
    StringNum number = 0;
    ASSERT_EQ((number / 1245).toString(), StringNum("0").toString());
}

TEST(StringNumTests, DIV_MORE_THAN_TEN) {
    StringNum number = 23986345;
    ASSERT_EQ((number / 11).toString(), StringNum("2180576").toString());
}

TEST(StringNumTests, DIV_NEW_DOZEN) {
    StringNum number = 23986345;
    ASSERT_EQ((number / 10).toString(), StringNum("2398634").toString());
}

TEST(StringNumTests, DIV_FIRST_NEG) {
    StringNum number = -23986345;
    ASSERT_EQ((number / 10).toString(), StringNum("-2398634").toString());
}

TEST(StringNumTests, DIV_SECOND_NEG) {
    StringNum number = 23986345;
    ASSERT_EQ((number / -10).toString(), StringNum("-2398634").toString());
}

TEST(StringNumTests, DIV_BOTH_NEG) {
    StringNum number = -23986345;
    ASSERT_EQ((number / -10).toString(), StringNum("2398634").toString());
}

TEST(StringNumTests, DIV_HARD) {
    StringNum number = 1400574;
    ASSERT_EQ((number / 14).toString(), StringNum("100041").toString());
}

TEST(StringNumTests, MOD_SIMPLE) {
    StringNum number = 16;
    ASSERT_EQ((number % 2).toString(), StringNum("0").toString());
}

TEST(StringNumTests, MOD_ONE_POS) {
    StringNum number = 987652123456;
    ASSERT_EQ((number % 1).toString(), StringNum("0").toString());
}

TEST(StringNumTests, MOD_ONE_NEG) {
    StringNum number = 23986345;
    ASSERT_EQ((number % -1).toString(), StringNum("0").toString());
}

TEST(StringNumTests, MOD_ZERO) {
    StringNum number = 0;
    ASSERT_EQ((number % 1245).toString(), StringNum("0").toString());
}

TEST(StringNumTests, MOD_MORE_THAN_TEN) {
    StringNum number = 23986345;
    ASSERT_EQ((number % 11).toString(), StringNum("9").toString());
}

TEST(StringNumTests, MOD_NEW_DOZEN) {
    StringNum number = 23986345;
    ASSERT_EQ((number % 10).toString(), StringNum("5").toString());
}

TEST(StringNumTests, MOD_FIRST_NEG) {
    StringNum number = -23986345;
    ASSERT_EQ((number % 10).toString(), StringNum("-5").toString());
}

TEST(StringNumTests, MOD_SECOND_NEG) {
    StringNum number = 23986345;
    ASSERT_EQ((number % -10).toString(), StringNum("5").toString());
}

TEST(StringNumTests, MOD_BOTH_NEG) {
    StringNum number = -23986345;
    ASSERT_EQ((number % -10).toString(), StringNum("-5").toString());
}

TEST(StringNumTests, MOD_HARD) {
    StringNum number = 1400574;
    ASSERT_EQ((number % 14).toString(), StringNum("0").toString());
}

TEST(StringNumTests, MOD_SIMPLE_POS_NEG) {
    StringNum number = 5;
    ASSERT_EQ((number % -3).toString(), StringNum("2").toString());
}

TEST(StringNumTests, MOD_SIMPLE_NEG_POS) {
    StringNum number = -5;
    ASSERT_EQ((number % 3).toString(), StringNum("-2").toString());
}