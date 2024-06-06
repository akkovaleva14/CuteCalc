#ifndef SRC_DEPOSIT_DEPOSITWINDOW_H
#define SRC_DEPOSIT_DEPOSITWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QWidget>
#include <vector>

#include "../controller/s21_deposit_controller.h"
#include "credit_deposit.h"
#include "ui_depositwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DepositWindow;
}
QT_END_NAMESPACE

class DepositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit DepositWindow(QWidget *parent = nullptr);
  ~DepositWindow();

 signals:
  void firstWindow();

 private slots:
  void back_btn_clicked();
  void clear_btn_clicked();
  void process_result();

 private:
  Ui::DepositWindow *ui;
  ControllerDeposit controller_deposit_{};
  void setReadOnlyElements(const QList<QLineEdit *> &elements);
  void setDefaultValues();
};

#endif  // SRC_DEPOSIT_DEPOSITWINDOW_H
