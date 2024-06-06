#ifndef SRC_CREDIT_DEPOSIT_CREDIT_DEPOSIT_H
#define SRC_CREDIT_DEPOSIT_CREDIT_DEPOSIT_H

#include <string.h>

enum false_zero_true_one { FALSE, TRUE };
enum ok_zero_error_one { OK, ERR };
enum annuity_zero_differentiated_one { ANNUITY, DIFFERENTIATED };
enum month_zero_year_one { MONTH, YEAR };

int validate_it(const char* str);
int is_digit(char ch);
int is_dot(char ch);

#endif
