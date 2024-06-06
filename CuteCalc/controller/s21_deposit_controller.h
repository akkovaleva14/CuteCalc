#ifndef SRC_CONTROLLER_S21_DEPOSIT_CONTROLLER_H_
#define SRC_CONTROLLER_S21_DEPOSIT_CONTROLLER_H_

#include "../model/s21_deposit_model.h"

class ControllerDeposit {
 public:
  ControllerDeposit() = default;
  ~ControllerDeposit() = default;

  void SetStartValues(const double deposit_amount, const double deposit_term,
                      const double interest_rate, const double tax_rate,
                      const int mode_periodicity, const int capitalization,
                      const double monthly_replenishment,
                      const double monthly_withdrawal);

  // void CalcAccruedInterest() { return deposit_.CalcAccruedInterest(); };
  // void CalcTaxAmount() { return deposit_.CalcTaxAmount(); };
  // void CalcDepositAmountByEnd() { deposit_.CalcDepositAmountByEnd(); };

  void CalcAccruedInterest();
  double GetAccruedInterest();
  double GetTaxAmount();
  double GetDepositAmountByEnd();

 private:
  DepositCalculator deposit_;
};

#endif  // SRC_CONTROLLER_S21_DEPOSIT_CONTROLLER_H_