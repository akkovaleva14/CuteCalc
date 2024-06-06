#ifndef SRC_CREDIT_DEPOSIT_CREDITWINDOW_H
#define SRC_CREDIT_DEPOSIT_CREDITWINDOW_H

#include <QWidget>

#include "credit_deposit.h"
#include "ui_creditwindow.h"
#include "../controller/s21_credit_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CreditWindow;
}
QT_END_NAMESPACE

class CreditWindow : public QWidget {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget *parent = nullptr);
  ~CreditWindow();

 signals:
  void firstWindow();

 private slots:
  void back_btn_clicked();
  void clear_btn_clicked();
  void process_result();

 private:
  Ui::CreditWindow *ui;
  ControllerCredit controller_credit_{};
};

#endif  // SRC_CREDIT_DEPOSIT_CREDITWINDOW_H
