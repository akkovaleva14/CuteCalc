#include "credit_deposit.h"

int is_digit(char ch) { return (ch >= '0' && ch <= '9') ? TRUE : FALSE; }
int is_dot(char ch) { return (ch == '.') ? TRUE : FALSE; }

int validate_it(const char* str) {
  int status = OK;
  int i = 0, dot_status = FALSE;
  while (str[i] != '\0') {
    if (is_digit(str[i]) == TRUE) {
      i++;
    } else if (is_dot(str[i]) == TRUE && dot_status == FALSE) {
      i++;
      dot_status = TRUE;
    } else {
      status = ERR;
      break;
    }
  }
  if (str[strlen(str) - 1] == '.') {
    status = ERR;
  }
  return status;
}
