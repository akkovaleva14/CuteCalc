#include "creditwindow.h"

#include "credit_deposit.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
  connect(ui->back_btn, SIGNAL(clicked()), this, SLOT(back_btn_clicked()));
  connect(ui->clear_btn, SIGNAL(clicked()), this, SLOT(clear_btn_clicked()));

  connect(ui->calculate_btn, SIGNAL(clicked()), this, SLOT(process_result()));
  connect(ui->total_cr_amount_lineEdit, SIGNAL(returnPressed()), this,
          SLOT(process_result()));
  connect(ui->term_lineEdit, SIGNAL(returnPressed()), this,
          SLOT(process_result()));
  connect(ui->interest_rate_lineEdit, SIGNAL(returnPressed()), this,
          SLOT(process_result()));

  ui->monthly_payment_lineEdit->setReadOnly(true);
  ui->overpayment_lineEdit->setReadOnly(true);
  ui->total_payment_lineEdit->setReadOnly(true);
  ui->annuity_radio_btn->setChecked(true);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::back_btn_clicked() {
  this->close();
  emit firstWindow();
}

void CreditWindow::clear_btn_clicked() {
  ui->total_cr_amount_lineEdit->clear();
  ui->term_lineEdit->clear();

  ui->interest_rate_lineEdit->clear();

  ui->annuity_radio_btn->setChecked(true);
  ui->differentiated_radio_btn->setChecked(false);

  ui->monthly_payment_lineEdit->clear();
  ui->overpayment_lineEdit->clear();
  ui->total_payment_lineEdit->clear();
}

void CreditWindow::process_result() {
  int status = OK;
  double monthly_payment = 0.0, overpayment_on_credit = 0.0,
         total_payment = 0.0;
  int type_an_or_dif = ANNUITY;

  double total_credit_amount = ui->total_cr_amount_lineEdit->text().toDouble();
  double term = ui->term_lineEdit->text().toDouble();
  double interest_rate = ui->interest_rate_lineEdit->text().toDouble();

  QByteArray ba_1 = ui->total_cr_amount_lineEdit->text().toLocal8Bit();
  char *input_val_1 = ba_1.data();
  QByteArray ba_2 = ui->term_lineEdit->text().toLocal8Bit();
  char *input_val_2 = ba_2.data();
  QByteArray ba_3 = ui->interest_rate_lineEdit->text().toLocal8Bit();
  char *input_val_3 = ba_3.data();
  QString input_1 = ui->total_cr_amount_lineEdit->text();
  QString input_2 = ui->term_lineEdit->text();
  QString input_3 = ui->interest_rate_lineEdit->text();
  if (input_1.isEmpty() || input_2.isEmpty() || input_3.isEmpty()) {
    status = ERR;
  }
  if (validate_it(input_val_1) == ERR || validate_it(input_val_2) == ERR ||
      validate_it(input_val_3) == ERR) {
    status = ERR;
  }

  if (ui->annuity_radio_btn->isChecked()) {
    type_an_or_dif = ANNUITY;
  } else {
    type_an_or_dif = DIFFERENTIATED;
  }

  double loan = total_credit_amount;
  double period = term;
  double rate = interest_rate;
  controller_credit_.SetStartValues(loan, period, rate);

  if (status == ERR) {
    ui->total_payment_lineEdit->setText("error");
  } else {
    if (type_an_or_dif == ANNUITY) {
      controller_credit_.CalcAnnuity();
      ui->monthly_payment_lineEdit->setText(
          QString("%L1").arg(controller_credit_.GetMonthPayment(), 0, 'f', 2));
      ui->overpayment_lineEdit->setText(
          QString("%L1").arg(controller_credit_.GetOverpayment(), 0, 'f', 2));
      ui->total_payment_lineEdit->setText(
          QString("%L1").arg(controller_credit_.GetTotalPayment(), 0, 'f', 2));

    } else if (type_an_or_dif == DIFFERENTIATED) {
      controller_credit_.CalcDifferentiated();
      ui->monthly_payment_lineEdit->setText(
          QString("%L1").arg(controller_credit_.GetFirstPayment(), 0, 'f', 2) +
          ".." +
          QString("%L1").arg(controller_credit_.GetLastPayment(), 0, 'f', 2));
      ui->overpayment_lineEdit->setText(
          QString("%L1").arg(controller_credit_.GetOverpayment(), 0, 'f', 2));
      ui->total_payment_lineEdit->setText(
          QString("%L1").arg(controller_credit_.GetTotalPayment(), 0, 'f', 2));
    }
  }
}
