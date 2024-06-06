#include "tests.h"

TEST(s21_model, unary_plus) {
  s21::Model model;
  model.SetExpression("5++5");
  EXPECT_EQ(model.Calculate(), "10");
}

TEST(s21_model, exponentional_test_0) {
  s21::Model model;
  model.SetExpression("0");
  EXPECT_EQ(model.Calculate(), "0");
}

TEST(s21_model, exponentional_test_1) {
  s21::Model model;
  model.SetExpression("2.3");
  EXPECT_EQ(model.Calculate(), "2.3");
}

TEST(s21_model, exponentional_test_2) {
  s21::Model model;
  model.SetExpression("2.3e1");
  EXPECT_EQ(model.Calculate(), "23");
}

TEST(s21_model, exponentional_test_3) {
  s21::Model model;
  model.SetExpression("2.3e-1");
  EXPECT_EQ(model.Calculate(), "0.23");
}

TEST(s21_model, exponentional_test_4) {
  s21::Model model;
  model.SetExpression("2.3e+1");
  EXPECT_EQ(model.Calculate(), "23");
}

TEST(s21_model, exponentional_test_5) {
  s21::Model model;
  model.SetExpression("2.3e+10");
  EXPECT_EQ(model.Calculate(), "23000000000");
}

TEST(s21_model, exponentional_test_6) {
  s21::Model model;
  model.SetExpression("2.3e-7");
  EXPECT_EQ(model.Calculate(), "0.0000002");
}

TEST(s21_model, exponentional_test_7) {
  s21::Model model;
  model.SetExpression("2.3e+20");
  EXPECT_EQ(model.Calculate(), "230000000000000000000");
}

TEST(s21_model, Pow1) {
  s21::Model model;
  model.SetExpression("2^3^2");
  EXPECT_EQ(model.Calculate(), "512");
}

TEST(s21_model, Triginometric1) {
  s21::Model model;
  model.SetExpression(
      "acos(cos(sin(atan(ln(sqrt((8 * ((1 + 2 + 4 * 3 - 3 * 7) / 4)) + "
      "133))))))");
  EXPECT_EQ(model.Calculate(), "0.922957");
}

TEST(s21_model, Triginometric2) {
  s21::Model model;
  model.SetExpression("tan(40) + asin(0.5)");
  EXPECT_EQ(model.Calculate(), "-0.5936162");
}

TEST(s21_model, Triginometric4) {
  s21::Model model;
  model.SetExpression("log(3) + log(4)");
  EXPECT_EQ(model.Calculate(), "1.0791812");
}

TEST(s21_model, SetVarX1) {
  s21::Model model;
  model.SetVarX(-2);
  model.SetExpression("x-x");
  EXPECT_EQ(model.Calculate(), "0");
}

TEST(s21_model, SetVarX2) {
  s21::Model model;
  model.SetVarX(-2);
  model.SetExpression("-x+x");
  EXPECT_EQ(model.Calculate(), "0");
}

TEST(s21_model, SetStep1) {
  s21::Model s21_model;
  s21_model.SetPlotRange(-10, 10, 0, 100);
  std::vector<double> x, y;
  std::vector<double> test_x = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0,
                                1,   2,  3,  4,  5,  6,  7,  8,  9,  10};
  std::vector<double> text_y = {100, 81, 64, 49, 36, 25, 16, 9,  4,  1,  0,
                                1,   4,  9,  16, 25, 36, 49, 64, 81, 100};
  s21_model.SetExpression("x^2");
  s21_model.SetStep(1);
  std::tie(x, y) = s21_model.Plot();
  for (auto it = x.begin(), it2 = y.begin(), it3 = test_x.begin(),
            it4 = text_y.begin();
       it != x.end(); it++, it2++, it3++, it4++) {
    EXPECT_EQ(*it, *it3);
    EXPECT_EQ(*it2, *it4);
  }
}

TEST(s21_model, ErrorUnknownError) {
  s21::Model model;
  model.SetExpression("0/0");
#ifdef MACOS
  EXPECT_EQ(model.Calculate(), "nan");
#else
  EXPECT_EQ(model.Calculate(), "-nan");
#endif
}

TEST(s21_model, ErrorUnknownError2) {
  s21::Model model;
  model.SetExpression("1/-0");
  EXPECT_EQ(model.Calculate(), "-inf");
}