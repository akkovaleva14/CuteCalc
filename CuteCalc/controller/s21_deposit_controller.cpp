#include "s21_deposit_controller.h"

void ControllerDeposit::SetStartValues(
    const double deposit_amount, const double deposit_term,
    const double interest_rate, const double tax_rate,
    const int mode_periodicity, const int capitalization,
    const double monthly_replenishment, const double monthly_withdrawal) {
  deposit_.SetStartValues(deposit_amount, deposit_term, interest_rate, tax_rate,
                          mode_periodicity, capitalization,
                          monthly_replenishment, monthly_withdrawal);
}

void ControllerDeposit::CalcAccruedInterest() {
  deposit_.CalcAccruedInterest();
}

double ControllerDeposit::GetAccruedInterest() {
  return deposit_.GetAccruedInterest();
}

double ControllerDeposit::GetTaxAmount() { return deposit_.GetTaxAmount(); }

double ControllerDeposit::GetDepositAmountByEnd() {
  return deposit_.GetDepositAmountByEnd();
}