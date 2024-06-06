#include "tests.h"

TEST(DigitTest, IsDigit) {
  EXPECT_TRUE(is_digit('0'));
  EXPECT_TRUE(is_digit('9'));
  EXPECT_FALSE(is_digit('A'));
  EXPECT_FALSE(is_digit('Z'));
  EXPECT_FALSE(is_digit('+'));
  EXPECT_FALSE(is_digit('-'));
  EXPECT_FALSE(is_digit(' '));
}

TEST(DotTest, IsDot) {
  EXPECT_TRUE(is_dot('.'));
  EXPECT_FALSE(is_dot('a'));
  EXPECT_FALSE(is_dot('1'));
  EXPECT_FALSE(is_dot(' '));
}

class ValidateItTest : public ::testing::Test {
 protected:
  std::string inputStr;
  void SetUp() override { inputStr = ""; }
};

TEST_F(ValidateItTest, ValidNumberWithOneDot) {
  inputStr = "123.45";
  EXPECT_EQ(validate_it(inputStr.c_str()), OK);
}

TEST_F(ValidateItTest, ValidNumberWithoutDot) {
  inputStr = "1234567890";
  EXPECT_EQ(validate_it(inputStr.c_str()), OK);
}

TEST_F(ValidateItTest, InvalidNumberWithExtraDots) {
  inputStr = "123..45";
  EXPECT_EQ(validate_it(inputStr.c_str()), ERR);
}

TEST_F(ValidateItTest, InvalidNumberWithNonDigitCharacter) {
  inputStr = "123abc";
  EXPECT_EQ(validate_it(inputStr.c_str()), ERR);
}

TEST_F(ValidateItTest, EmptyString) {
  inputStr = "";
  EXPECT_EQ(validate_it(inputStr.c_str()), OK);
}

TEST_F(ValidateItTest, StringEndingWithDot) {
  inputStr = "123.";
  EXPECT_EQ(validate_it(inputStr.c_str()), ERR);
}