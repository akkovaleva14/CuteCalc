#ifndef SRC_MODEL_S21_DEPOSIT_MODEL_H_
#define SRC_MODEL_S21_DEPOSIT_MODEL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum nope_zero_yep_one { NOPE, YEP };
enum monthly_zero_annually_one { MONTHLY, ANNUALLY };

class DepositCalculator {
 public:
  DepositCalculator() = default;
  DepositCalculator(const double deposit_amount, const double deposit_term,
                    const double interest_rate, const double tax_rate,
                    const int mode_periodicity, const int capitalization,
                    const double monthly_replenishment,
                    const double monthly_withdrawal)
      : deposit_amount_(deposit_amount),
        deposit_term_(deposit_term),
        interest_rate_(interest_rate),
        tax_rate_(tax_rate),
        mode_periodicity_(mode_periodicity),
        capitalization_(capitalization),
        monthly_replenishment_(monthly_replenishment),
        monthly_withdrawal_(monthly_withdrawal){};
  ~DepositCalculator() = default;

  void SetStartValues(const double deposit_amount, const double deposit_term,
                      const double interest_rate, const double tax_rate,
                      const int mode_periodicity, const int capitalization,
                      const double monthly_replenishment,
                      const double monthly_withdrawal);

  void CalcAccruedInterest();

  double GetAccruedInterest() { return accrued_interest_; };
  double GetTaxAmount() { return tax_amount_; };
  double GetDepositAmountByEnd() { return deposit_by_the_end_; };

 private:
  double deposit_amount_{}, deposit_term_{};
  double interest_rate_{}, tax_rate_{};
  int mode_periodicity_{}, capitalization_{};
  double monthly_replenishment_{}, monthly_withdrawal_{};
  double accrued_interest_{}, tax_amount_{}, deposit_by_the_end_{};
};

#endif  // SRC_MODEL_S21_DEPOSIT_MODEL_H_