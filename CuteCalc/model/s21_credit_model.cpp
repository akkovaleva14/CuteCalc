#include "s21_credit_model.h"

void CreditCalculator::SetStartValues(const double loan, const int period,
                                      const double rate) {
  loan_ = loan;
  period_ = period;
  rate_ = rate;
}

void CreditCalculator::CalcAnnuity() {
  month_payment_ = CalcMonthAnnuity();
  total_payment_ = month_payment_ * period_;
  overpayment_ = total_payment_ - loan_;
}

double CreditCalculator::CalcMonthAnnuity() {
  double month_rate = rate_ / 12.0 / 100.0;
  double temp = std::pow((1 + month_rate), period_);
  return loan_ * month_rate * temp / (temp - 1);
}

void CreditCalculator::CalcDifferentiated() {
  double Sn = loan_ / period_;
  double percent =
      rate_ / 100 * (days_in_year_ / months_in_year_) / days_in_year_;
  total_payment_ = 0;

  for (int i = 0; i < period_; i++) {
    double payment = Sn + (loan_ - i * Sn) * percent;
    if (i == 0) {
      first_payment_ = payment;
    } else {
      last_payment_ = payment;
    }
    total_payment_ += payment;
  }

  overpayment_ = total_payment_ - loan_;
}
