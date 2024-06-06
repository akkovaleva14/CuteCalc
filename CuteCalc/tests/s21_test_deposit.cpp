#include "tests.h"

class DepositCalculatorTest : public ::testing::Test {
 protected:
  DepositCalculator calculator;
};

TEST_F(DepositCalculatorTest, CalcAccruedInterest) {
  double depositAmount = 1000;
  double depositTerm = 12;
  double interestRate = 5;
  double taxRate = 0;
  int modePeriodicity = MONTHLY;
  int capitalization = NOPE;
  double monthlyReplenishment = 0;
  double monthlyWithdrawal = 0;

  calculator.SetStartValues(depositAmount, depositTerm, interestRate, taxRate,
                            modePeriodicity, capitalization,
                            monthlyReplenishment, monthlyWithdrawal);
  calculator.CalcAccruedInterest();
  double expectedAccruedInterest = 600;
  EXPECT_DOUBLE_EQ(calculator.GetAccruedInterest(), expectedAccruedInterest);
}

TEST_F(DepositCalculatorTest, CalculateTaxAmount) {
  double depositAmount = 1000;
  double depositTerm = 12;
  double interestRate = 5;
  double taxRate = 0;
  int modePeriodicity = MONTHLY;
  int capitalization = NOPE;
  double monthlyReplenishment = 0;
  double monthlyWithdrawal = 0;

  calculator.SetStartValues(depositAmount, depositTerm, interestRate, taxRate,
                            modePeriodicity, capitalization,
                            monthlyReplenishment, monthlyWithdrawal);
  calculator.CalcAccruedInterest();
  double expectedTaxAmount = 0;
  EXPECT_DOUBLE_EQ(calculator.GetTaxAmount(), expectedTaxAmount);
}

TEST_F(DepositCalculatorTest, CalculateDepositAmountByEnd) {
  double depositAmount = 1000;
  double depositTerm = 12;
  double interestRate = 5;
  double taxRate = 0;
  int modePeriodicity = MONTHLY;
  int capitalization = NOPE;
  double monthlyReplenishment = 0;
  double monthlyWithdrawal = 0;

  calculator.SetStartValues(depositAmount, depositTerm, interestRate, taxRate,
                            modePeriodicity, capitalization,
                            monthlyReplenishment, monthlyWithdrawal);
  calculator.CalcAccruedInterest();
  double expectedDepositAmount = 1600;
  EXPECT_DOUBLE_EQ(calculator.GetDepositAmountByEnd(), expectedDepositAmount);
}

TEST_F(DepositCalculatorTest, CalcAccruedInterest_PeriodicityYearly_Capit) {
  double depositAmount = 1000;
  double depositTerm = 12;
  double interestRate = 5;
  double taxRate = 0;
  int modePeriodicity = ANNUALLY;
  int capitalization = YEP;
  double monthlyReplenishment = 0;
  double monthlyWithdrawal = 0;

  calculator.SetStartValues(depositAmount, depositTerm, interestRate, taxRate,
                            modePeriodicity, capitalization,
                            monthlyReplenishment, monthlyWithdrawal);
  calculator.CalcAccruedInterest();
  double expectedAccruedInterest = 50;
  EXPECT_DOUBLE_EQ(calculator.GetAccruedInterest(), expectedAccruedInterest);
}

TEST_F(DepositCalculatorTest,
       CalculateDepositAmountByEnd_PeriodicityYearly_Capit) {
  double depositAmount = 1000;
  double depositTerm = 12;
  double interestRate = 5;
  double taxRate = 0;
  int modePeriodicity = ANNUALLY;
  int capitalization = YEP;
  double monthlyReplenishment = 0;
  double monthlyWithdrawal = 0;

  calculator.SetStartValues(depositAmount, depositTerm, interestRate, taxRate,
                            modePeriodicity, capitalization,
                            monthlyReplenishment, monthlyWithdrawal);
  calculator.CalcAccruedInterest();
  double expectedDepositAmount = 1100;
  EXPECT_DOUBLE_EQ(calculator.GetDepositAmountByEnd(), expectedDepositAmount);
}
