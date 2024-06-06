#include "s21_deposit_model.h"

void DepositCalculator::SetStartValues(
    const double deposit_amount, const double deposit_term,
    const double interest_rate, const double tax_rate,
    const int mode_periodicity, const int capitalization,
    const double monthly_replenishment, const double monthly_withdrawal) {
  deposit_amount_ = deposit_amount;
  deposit_term_ = deposit_term;
  interest_rate_ = interest_rate;
  tax_rate_ = tax_rate;
  mode_periodicity_ = mode_periodicity;
  capitalization_ = capitalization;
  monthly_replenishment_ = monthly_replenishment;
  monthly_withdrawal_ = monthly_withdrawal;
};

void DepositCalculator::CalcAccruedInterest() {
  double res = 0;
  if (mode_periodicity_ == MONTHLY) {
    mode_periodicity_ = 12;
    deposit_term_ *= 12;
  }
  monthly_replenishment_ *= mode_periodicity_;
  monthly_withdrawal_ *= mode_periodicity_;
  for (int i = 0; (double)i < deposit_term_; i++) {
    double temp = 0;
    if (mode_periodicity_ == 12) {
      temp = deposit_amount_ * interest_rate_ / 100 / mode_periodicity_;
    } else if (mode_periodicity_ == ANNUALLY) {
      if (i % 11 == 0 && i != 0) {
        temp = deposit_amount_ * interest_rate_ / 100;
      }
    }
    deposit_amount_ += monthly_replenishment_;
    deposit_amount_ -= monthly_withdrawal_;
    if (capitalization_ == YEP) {
      deposit_amount_ += temp;
    }
    res += temp;
  }
  accrued_interest_ = res;
  tax_amount_ = accrued_interest_ * tax_rate_ / 100;
  deposit_by_the_end_ = deposit_amount_ + accrued_interest_ - tax_amount_;
}
