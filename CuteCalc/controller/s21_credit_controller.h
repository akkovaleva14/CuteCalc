#ifndef SRC_CONTROLLER_S21_CREDIT_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CREDIT_CONTROLLER_H_

#include "../model/s21_credit_model.h"

class ControllerCredit {
 public:
  ControllerCredit() = default;
  ~ControllerCredit() = default;

  void SetStartValues(const double loan, const double period,
                      const double rate);
  void CalcAnnuity();
  void CalcDifferentiated();
  double GetMonthPayment();
  double GetOverpayment();
  double GetTotalPayment();
  double GetFirstPayment();
  double GetLastPayment();

 private:
  CreditCalculator credit_;
};

#endif  // SRC_CONTROLLER_S21_CREDIT_CONTROLLER_H_