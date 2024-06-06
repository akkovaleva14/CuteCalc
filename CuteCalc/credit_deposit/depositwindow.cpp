#include "depositwindow.h"

#include "credit_deposit.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::DepositWindow) {
  ui->setupUi(this);

  connect(ui->back_btn, &QPushButton::clicked, this,
          &DepositWindow::back_btn_clicked);
  connect(ui->clear_btn, &QPushButton::clicked, this,
          &DepositWindow::clear_btn_clicked);
  connect(ui->calculate_btn, &QPushButton::clicked, this,
          &DepositWindow::process_result);
  connect(ui->deposit_amount_lineEdit, &QLineEdit::returnPressed, this,
          &DepositWindow::process_result);
  connect(ui->deposit_term_lineEdit, &QLineEdit::returnPressed, this,
          &DepositWindow::process_result);
  connect(ui->interest_rate_lineEdit, &QLineEdit::returnPressed, this,
          &DepositWindow::process_result);
  connect(ui->tax_rate_lineEdit, &QLineEdit::returnPressed, this,
          &DepositWindow::process_result);
  connect(ui->monthly_replenishment_lineEdit, &QLineEdit::returnPressed, this,
          &DepositWindow::process_result);
  connect(ui->monthly_withdrawal_lineEdit, &QLineEdit::returnPressed, this,
          &DepositWindow::process_result);

  setReadOnlyElements({ui->accrued_interest_lineEdit, ui->tax_amount_lineEdit,
                       ui->deposit_by_the_end_lineEdit});
  setDefaultValues();
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::setReadOnlyElements(const QList<QLineEdit*>& elements) {
  foreach (auto& element, elements) {
    element->setReadOnly(true);
  }
}

void DepositWindow::setDefaultValues() {
  ui->period_monthly_radio_btn->setChecked(true);
}

void DepositWindow::back_btn_clicked() {
  this->close();
  emit firstWindow();
}

void DepositWindow::clear_btn_clicked() {
  ui->deposit_amount_lineEdit->clear();
  ui->deposit_term_lineEdit->clear();
  ui->interest_rate_lineEdit->clear();
  ui->tax_rate_lineEdit->clear();
  setDefaultValues();
  ui->capitalization_checkBox->setChecked(false);
  ui->monthly_replenishment_lineEdit->clear();
  ui->monthly_withdrawal_lineEdit->clear();
  ui->accrued_interest_lineEdit->clear();
  ui->tax_amount_lineEdit->clear();
  ui->deposit_by_the_end_lineEdit->clear();
}

void DepositWindow::process_result() {
  int status = OK, capitalization = FALSE, mode_periodicity = MONTH;
  double deposit_amount = ui->deposit_amount_lineEdit->text().toDouble();
  double deposit_term = ui->deposit_term_lineEdit->text().toDouble();
  double interest_rate = ui->interest_rate_lineEdit->text().toDouble();
  double tax_rate = ui->tax_rate_lineEdit->text().toDouble();
  double monthly_replenishment =
      ui->monthly_replenishment_lineEdit->text().toDouble();
  double monthly_withdrawal =
      ui->monthly_withdrawal_lineEdit->text().toDouble();

  char* input_val_1 = ui->deposit_amount_lineEdit->text().toLocal8Bit().data();
  char* input_val_2 = ui->deposit_term_lineEdit->text().toLocal8Bit().data();
  char* input_val_3 = ui->interest_rate_lineEdit->text().toStdString().data();
  char* input_val_4 = ui->tax_rate_lineEdit->text().toStdString().data();
  char* input_val_5 =
      ui->monthly_replenishment_lineEdit->text().toStdString().data();
  char* input_val_6 =
      ui->monthly_withdrawal_lineEdit->text().toStdString().data();
  if (validate_it(input_val_1) == ERR || validate_it(input_val_2) == ERR ||
      validate_it(input_val_3) == ERR || validate_it(input_val_4) == ERR ||
      validate_it(input_val_5) == ERR || validate_it(input_val_6) == ERR) {
    status = ERR;
  }

  QString input_1 = ui->deposit_amount_lineEdit->text();
  QString input_2 = ui->deposit_term_lineEdit->text();
  QString input_3 = ui->interest_rate_lineEdit->text();
  QString input_4 = ui->tax_rate_lineEdit->text();
  QString input_5 = ui->monthly_replenishment_lineEdit->text();
  QString input_6 = ui->monthly_withdrawal_lineEdit->text();
  if (input_1.isEmpty() || input_2.isEmpty() || input_3.isEmpty() ||
      input_4.isEmpty() || input_5.isEmpty() || input_6.isEmpty()) {
    status = ERR;
  }

  if (ui->capitalization_checkBox->isChecked()) {
    capitalization = TRUE;
  }

  if (ui->period_monthly_radio_btn->isChecked()) {
    mode_periodicity = MONTH;
  } else if (ui->period_yearly_radio_btn->isChecked()) {
    mode_periodicity = YEAR;
  }

  controller_deposit_.SetStartValues(
      deposit_amount, deposit_term, interest_rate, tax_rate, mode_periodicity,
      capitalization, monthly_replenishment, monthly_withdrawal);

  if (status == ERR) {
    QMessageBox::warning(this, "Oopsie!", "Input is invalid");
  } else {
    controller_deposit_.CalcAccruedInterest();
    ui->accrued_interest_lineEdit->setText(QString("%L1").arg(
        controller_deposit_.GetAccruedInterest(), 0, 'f', 2));
    ui->tax_amount_lineEdit->setText(
        QString("%L1").arg(controller_deposit_.GetTaxAmount(), 0, 'f', 2));
    ui->deposit_by_the_end_lineEdit->setText(QString("%L1").arg(
        controller_deposit_.GetDepositAmountByEnd(), 0, 'f', 2));
  }
}
